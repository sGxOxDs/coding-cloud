#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{
	width = 1;
	length = 1;
}

void Rectangle::setWidth(int w)
{
	if (w > 0 && w <= 20)
		width = w;
	else
		cout << w << " is error value." << endl;
}

void Rectangle::setLength(int l)
{
	if (l > 0 && l <= 20)
		length = l;
	else
		cout << l << " is error value." << endl;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getLength()
{
	return length;
}

int Rectangle::computePerimeter()
{
	return (width + length) * 2;
}

int Rectangle::calculateArea()
{
	return width * length;
}

void Rectangle::setFillCharacter(char c)
{
	draw(c);
}
void Rectangle::draw(char c)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1 || i == 0 || i == length - 1)
				cout << c << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}