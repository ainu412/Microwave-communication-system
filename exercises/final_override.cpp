#include <iostream>
using namespace std;
class BillGates final {
public:
	void assest() {
		cout << "�����������Ų�����,�������Ӵ�!" << endl;
	}
};
class Dad {
public:
	void eat() {
		cout << "�ֱ��ڳԷ�" << endl;
	}
};
class Mom {
public:
	virtual void faceScore() {
		cout << "�������Ŷ�ׯ" << endl;
	}
	virtual void rules()final {
		cout << "�ҹ�:����,�޻�" << endl;
	}
};
class Me :public Dad, public Mom{
public:
	//void rules();������д!!
	void faceScore() override {//virtual��������ʱ�ɵ��Լ���!�����virtual����д,д�˵Ļ��Լ�������Ҳ�����޸�
		cout << "�һ�����" << endl;
	}
	void eat() {//��ͨ����������д!ֻ�Ƕ���ʱ���ܵ���
		cout << "���ڳԷ���~" << endl;
	}
};
class Daughter :public Me {
public:
	void faceScore() override {
		cout << "Ů����ʾ�ܽ���" << endl;
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
	party(me, daughter, daughter);//Ů����ʾ�ܽ���
	//ֻҪͬ������һ����virtual��,��ô�̳е�����ͬ����������virtual�������ɵ�!

	return 0;
}

