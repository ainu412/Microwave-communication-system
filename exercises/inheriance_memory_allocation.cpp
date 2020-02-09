#include <iostream>
using namespace std;

class Father {
public:
	virtual void func1() { cout << "Father::func1" << endl; }
	virtual void func2() { cout << "Father::func2" << endl; }
	virtual void func3() { cout << "Father::func3" << endl; }
	void func4() { cout << "非虚函数：Father::func4" << endl; }
public:  //为了便于测试main函数调取数据成员，特别改用public
	int x = 100;
	int y = 200;
	static int z;
};
int Father::z = 0;
class Mother {
public:
	virtual void handle1() { cout << __FUNCTION__ << endl; }
	void handle2() { cout << __FUNCTION__ << endl; }
	void handle3() { cout << __FUNCTION__ << endl; }

};
class Son :public Father,public Mother{
public:
	void func1() { cout << "Son::func1" << endl; }
	void handle1(){ cout << __FUNCTION__ << endl; }
	virtual void boy() { cout << __FUNCTION__ << endl; }
	int m = 400;
	int n = 500;
};
typedef void (*func_t)(void);

int main1(void) {
	Father father;

	// 含有虚函数的对象的内存中，最先存储的就是“虚函数表”
	cout << "对象地址：" << (int*)&father << endl;

	int* vptr = (int*)*(int*)&father;
	cout << "虚函数表指针vptr：" << vptr << endl;

	cout << "调用第1个虚函数: ";
	((func_t) * (vptr + 0))();

	cout << "调用第2个虚函数：";
	((func_t) * (vptr + 1))();

	cout << "调用第3个虚函数: ";
	((func_t) * (vptr + 2))();


	cout << "第1个数据成员的地址: " << endl;
	cout << &father.x << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "第1个数据成员的值：" << endl;
	cout << std::dec << father.x << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "第2个数据成员的地址: " << endl;
	cout << &father.y << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "第2个数据成员的值：" << endl;
	cout << std::dec << father.y << endl;
	cout << *(int*)((int)&father + 8) << endl;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	Father father2;
	cout << "father的虚函数表：";
	cout << *(int*)(*(int*)&father) << endl;
	cout << "father2的虚函数表：";
	cout << *(int*)(*(int*)&father2) << endl;

	//②使用继承的虚函数表
	Son son;
	int* vptr2 = (int*)*(int*)&son;
	//cout << "第一个虚函数表指针：" << vptr2 << endl;

	for (int i = 0; i < 4; i++) {
		cout << "调用第" << i + 1 << "个虚函数:";
		((func_t) * (vptr2 + i))();
	}

	for (int i = 0; i < 2; i++) {
		cout << *(int*)((int)&son + 4 + i * 4) << endl;
	}

	int* vptr3 = (int*)*((int*)&son + 3);
	for (int i = 0; i < 1; i++) {
		cout << "调用第" << i + 1 << "个虚函数:";
		((func_t) * (vptr3 + i))();
	}

	for (int i = 0; i < 2; i++) {
		cout << *(int*)((int)&son + 16 + i * 4) << endl;
	}
	system("pause");
	return 0;
}
