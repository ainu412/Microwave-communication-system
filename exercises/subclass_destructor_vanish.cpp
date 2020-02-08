#include <iostream>
using namespace std;

class Dad {
public:
	Dad(const char* name = "中国人") {
		cout << __FUNCTION__ << endl;

		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}
	//~Dad(){  //不加virtual则子类析构函数消失,内存泄漏
	virtual ~Dad() {
		cout << __FUNCTION__ << endl;
		if (name) {
			delete[] name;
			name = NULL;
		}
	}

private:
	char* name;
};

class Son:public Dad {
public:
	Son(string game = "王者", const char* name = "中国人") :Dad(name) {
		cout << __FUNCTION__ << endl;
		int len = game.length() + 1;
		this->game = new char[len];
		strcpy_s(this->game, len, game.c_str());
	}

	~Son() {
		cout << __FUNCTION__ << endl;
		if (game) {
			delete[] game;
			game = NULL;
		}
	}
private:
	char* game;
};

int main3() {
		cout << "----- case 1 :父类指针指向父类构造函数,指针在delete后,其所指函数随之消亡-----" << endl;
		Dad* dad = new Dad();
		delete dad;

	{	
		cout << "----- case 2 :子类对象创建,块结束后消亡-----" << endl;
		Son son;
	}
	
		cout << "--------------父类指针指向父类构造函数-----" << endl;
		Son* son = new Son();
		delete son;
	
	
		cout << "----- case 3 :父类指针指向子类构造函数-----" << endl;
		Dad* dad3 = new Son();
		delete dad3;//因指针为dad型故析构时没有析构son
	
	return 0;
}