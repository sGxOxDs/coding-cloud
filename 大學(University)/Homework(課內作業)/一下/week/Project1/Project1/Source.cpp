#include <iostream>
#include "Rectangle.h"
using namespace std;
/*
	�x��class����
	�p��P�� �p�⭱�n ø�s�Ť߹�
*/


int main()
{
	Rectangle rectangle;
	int temp;
	char c;
	cout << "Width: ";
	cin >> temp;
	rectangle.setWidth(temp);
	//cout << rectangle.getWidth() << endl;

	cout << "Length: ";
	cin >> temp;
	rectangle.setLength(temp);
	//cout << rectangle.getLength() << endl;

	//cout << "Perimeter: ";
	//cout << rectangle.computePerimeter() << endl;
	//cout << "Area: ";
	//cout << rectangle.calculateArea() << endl;

	cout << "FillCharacter: ";
	cin >> c;
	cout << endl;

	rectangle.setFillCharacter(c);
	cout << "Width: ";
	cout << rectangle.getWidth() << endl;
	cout << "Length: ";
	cout << rectangle.getLength() << endl;
	cout << "Perimeter: ";
	cout << rectangle.computePerimeter() << endl;
	cout << "Area: ";
	cout << rectangle.calculateArea() << endl;

	system("pause");


}