#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
class Rectangle
{
	public:
		Rectangle();
		void setWidth(int); 
		void setLength(int);
		int getWidth();
		int getLength();
		int computePerimeter();
		int calculateArea();
		void setFillCharacter(char);
		void draw(char);

	private:
		int width;
		int length;
};
#endif

