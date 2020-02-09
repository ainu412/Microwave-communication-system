#include <iostream>
using namespace std;

class Father {
public:
	virtual void func1() { cout << "Father::func1" << endl; }
	virtual void func2() { cout << "Father::func2" << endl; }
	virtual void func3() { cout << "Father::func3" << endl; }
	void func4() { cout << "���麯����Father::func4" << endl; }
public:  //Ϊ�˱��ڲ���main������ȡ���ݳ�Ա���ر����public
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

	// �����麯���Ķ�����ڴ��У����ȴ洢�ľ��ǡ��麯����
	cout << "�����ַ��" << (int*)&father << endl;

	int* vptr = (int*)*(int*)&father;
	cout << "�麯����ָ��vptr��" << vptr << endl;

	cout << "���õ�1���麯��: ";
	((func_t) * (vptr + 0))();

	cout << "���õ�2���麯����";
	((func_t) * (vptr + 1))();

	cout << "���õ�3���麯��: ";
	((func_t) * (vptr + 2))();


	cout << "��1�����ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.x << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "��1�����ݳ�Ա��ֵ��" << endl;
	cout << std::dec << father.x << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "��2�����ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.y << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "��2�����ݳ�Ա��ֵ��" << endl;
	cout << std::dec << father.y << endl;
	cout << *(int*)((int)&father + 8) << endl;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	Father father2;
	cout << "father���麯����";
	cout << *(int*)(*(int*)&father) << endl;
	cout << "father2���麯����";
	cout << *(int*)(*(int*)&father2) << endl;

	//��ʹ�ü̳е��麯����
	Son son;
	int* vptr2 = (int*)*(int*)&son;
	//cout << "��һ���麯����ָ�룺" << vptr2 << endl;

	for (int i = 0; i < 4; i++) {
		cout << "���õ�" << i + 1 << "���麯��:";
		((func_t) * (vptr2 + i))();
	}

	for (int i = 0; i < 2; i++) {
		cout << *(int*)((int)&son + 4 + i * 4) << endl;
	}

	int* vptr3 = (int*)*((int*)&son + 3);
	for (int i = 0; i < 1; i++) {
		cout << "���õ�" << i + 1 << "���麯��:";
		((func_t) * (vptr3 + i))();
	}

	for (int i = 0; i < 2; i++) {
		cout << *(int*)((int)&son + 16 + i * 4) << endl;
	}
	system("pause");
	return 0;
}
