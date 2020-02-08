#include <iostream>
using namespace std;

typedef void(*func_t)(void);
#define NON_STATIC_DATA_NUM 2	 //继承的和自己的
#define VIRTUAL_SELF_FUNC_NUM 4	 //继承的虚函数与自己的任何函数总量
class Father {
public:
	Father() :x(100), y(200) {}
	virtual void func1() {
		cout << __FUNCTION__ << endl;
	}
	virtual void func2() {
		cout << __FUNCTION__ << endl;
	}
	virtual void func3() {
		cout << __FUNCTION__ << endl;
	}

	static int z;
	int x = 300;
	int y = 400;
};

class Mother {
public:
	Mother() :m(300), n(400) {}
	virtual void handle1() {
		cout << __FUNCTION__ << endl;
	}
	void handle2() {
		cout << __FUNCTION__ << endl;
	}
	void handle3() {
		cout << __FUNCTION__ << endl;
	}
public:
	int m = 100;
	int n = 200;
};

class Son :public Mother, public Father {
public:
	Son() :s(500) {}
	void son() {
		cout << __FUNCTION__ << endl;
	}
	int s = 500;
};

int main() {
	Son father;
	int* vptr = (int*)*(int*)(&father);
	//证明:对象中最先存储vptr
	cout << "对象地址:" << (int*)&father << "中存的是虚函数指针地址:" << vptr << endl;

		((func_t) * ((int*)*(int*)&father + 0))();
	((func_t) * ((int*)*(int*)&father + 1))();
	((func_t) * ((int*)*(int*)&father + 2))();

	//通过vptr访问所有虚函数=>vptr指向虚函数表首地址
	for (int i = 0; i < VIRTUAL_SELF_FUNC_NUM; i++) {
		((func_t) * ((int*)*(int*)&f + i))();
	}

	//通过对象地址访问对象的三个数据成员地址和值(静态数据成员存储在类中,不能通过对象地址查看)
	for (int i = 0; i < NON_STATIC_DATA_NUM; i++) {
		cout << "第" << i + 1 << "个非静态数据成员的十六进制地址:" << hex << int(&f) + 4 + 4 * i << " = " << &(f.m) << endl;
	}

	cout << "及值:" << dec << *(int*)(int(&f) + 4 * 1) << " = " << f.m << endl;
	cout << "及值:" << dec << *(int*)(int(&f) + 4 * 2) << " = " << f.n << endl;
	cout << "及值:" << dec << *(int*)(int(&f) + 4 * 3) << " = " << f.x << endl;
	cout << "及值:" << dec << *(int*)(int(&f) + 4 * 4) << " = " << f.y << endl;
	cout << "及值:" << dec << *(int*)(int(&f) + 4 * 5) << " = " << f.s << endl;

	//通过

	system("pause");
	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//class Father {
//public:
//	virtual void func1() { cout << "Father::func1()" << endl; }
//	virtual void func2() { cout << "Father::func2()" << endl; }
//	virtual void func3() { cout << "Father::func3()" << endl; }
//	void func4() { cout << "非虚函数：Father::func4()" << endl; }
//public:
//	int x = 200;
//	int y = 300;
//};
//
//typedef void(*func_t)(void);
//
//int main(void) {
//	Father father;
//	int* vptr = (int*)*(int*)&father;
//
//	((func_t) * ((int*)*(int*)&father + 0))();
//	((func_t) * ((int*)*(int*)&father + 1))();
//	((func_t) * ((int*)*(int*)&father + 2))();
//
//
//	return 0;
//}