#include <iostream>
using namespace std;

class Shape {
public:
	Shape(string color = "WHITE") {
		this->color = color;
	}
	string getColor() { //公用功能,取得各自数据
		return color; 
	}
	virtual int area() = 0;//仅虚拟函数允许纯说明符,且纯说明符仅允许=0

private:
	string color;
};

class Circle:public Shape {
public:
	Circle(int radius = 0, string color = "WHITE") :Shape(color), radius(radius) {}//相当于this->radius = radius;

	int area() { //纯虚类在子类中实现这个功能
		return 3.14 * radius * radius; 
	}

private:
	int radius;
};
int main87() {
	Circle c;

	return 0;
}