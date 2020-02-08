#include <iostream>
using namespace std;

class Dad {
public:
	Dad(const char* name = "�й���") {
		cout << __FUNCTION__ << endl;

		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}
	//~Dad(){  //����virtual����������������ʧ,�ڴ�й©
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
	Son(string game = "����", const char* name = "�й���") :Dad(name) {
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
		cout << "----- case 1 :����ָ��ָ���๹�캯��,ָ����delete��,����ָ������֮����-----" << endl;
		Dad* dad = new Dad();
		delete dad;

	{	
		cout << "----- case 2 :������󴴽�,�����������-----" << endl;
		Son son;
	}
	
		cout << "--------------����ָ��ָ���๹�캯��-----" << endl;
		Son* son = new Son();
		delete son;
	
	
		cout << "----- case 3 :����ָ��ָ�����๹�캯��-----" << endl;
		Dad* dad3 = new Son();
		delete dad3;//��ָ��Ϊdad�͹�����ʱû������son
	
	return 0;
}