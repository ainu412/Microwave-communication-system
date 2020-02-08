#include <iostream>
using namespace std;
class BillGates final {
public:
	void assest() {
		cout << "我死后所有遗产捐献,不留给子代!" << endl;
	}
};
class Dad {
public:
	void eat() {
		cout << "爸比在吃饭" << endl;
	}
};
class Mom {
public:
	virtual void faceScore() {
		cout << "麻麻优雅端庄" << endl;
	}
	virtual void rules()final {
		cout << "家规:善良,无悔" << endl;
	}
};
class Me :public Dad, public Mom{
public:
	//void rules();不能再写!!
	void faceScore() override {//virtual函数顶替时可调自己的!子类的virtual不必写,写了的话自己的子类也可以修改
		cout << "我火辣辣" << endl;
	}
	void eat() {//普通函数可以再写!只是顶替时不能调用
		cout << "我在吃饭饭~" << endl;
	}
};
class Daughter :public Me {
public:
	void faceScore() override {
		cout << "女儿表示很娇柔" << endl;
	}
};
void party(Dad& dad, Mom& mom, Me& me) {
	dad.eat();
	mom.faceScore();
	me.faceScore();
}
int main4() {
	Me me;
	Daughter daughter;
	party(me, daughter, daughter);//女儿表示很娇柔
	//只要同名函数一个是virtual了,那么继承的所有同名函数都是virtual都是自由的!

	return 0;
}

