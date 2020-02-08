#include <iostream>
using namespace std;

class Shape {
public:
	Shape(string color = "WHITE") {
		this->color = color;
	}
	string getColor() { //���ù���,ȡ�ø�������
		return color; 
	}
	virtual int area() = 0;//�����⺯������˵����,�Ҵ�˵����������=0

private:
	string color;
};

class Circle:public Shape {
public:
	Circle(int radius = 0, string color = "WHITE") :Shape(color), radius(radius) {}//�൱��this->radius = radius;

	int area() { //��������������ʵ���������
		return 3.14 * radius * radius; 
	}

private:
	int radius;
};
int main87() {
	Circle c;

	return 0;
}