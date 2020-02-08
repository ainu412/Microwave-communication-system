#include <iostream>
using namespace std;

typedef void(*func_t)(void);
#define NON_STATIC_DATA_NUM 2	 //�̳еĺ��Լ���
#define VIRTUAL_SELF_FUNC_NUM 4	 //�̳е��麯�����Լ����κκ�������
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
	//֤��:���������ȴ洢vptr
	cout << "�����ַ:" << (int*)&father << "�д�����麯��ָ���ַ:" << vptr << endl;

		((func_t) * ((int*)*(int*)&father + 0))();
	((func_t) * ((int*)*(int*)&father + 1))();
	((func_t) * ((int*)*(int*)&father + 2))();

	//ͨ��vptr���������麯��=>vptrָ���麯�����׵�ַ
	for (int i = 0; i < VIRTUAL_SELF_FUNC_NUM; i++) {
		((func_t) * ((int*)*(int*)&f + i))();
	}

	//ͨ�������ַ���ʶ�����������ݳ�Ա��ַ��ֵ(��̬���ݳ�Ա�洢������,����ͨ�������ַ�鿴)
	for (int i = 0; i < NON_STATIC_DATA_NUM; i++) {
		cout << "��" << i + 1 << "���Ǿ�̬���ݳ�Ա��ʮ�����Ƶ�ַ:" << hex << int(&f) + 4 + 4 * i << " = " << &(f.m) << endl;
	}

	cout << "��ֵ:" << dec << *(int*)(int(&f) + 4 * 1) << " = " << f.m << endl;
	cout << "��ֵ:" << dec << *(int*)(int(&f) + 4 * 2) << " = " << f.n << endl;
	cout << "��ֵ:" << dec << *(int*)(int(&f) + 4 * 3) << " = " << f.x << endl;
	cout << "��ֵ:" << dec << *(int*)(int(&f) + 4 * 4) << " = " << f.y << endl;
	cout << "��ֵ:" << dec << *(int*)(int(&f) + 4 * 5) << " = " << f.s << endl;

	//ͨ��

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
//	void func4() { cout << "���麯����Father::func4()" << endl; }
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