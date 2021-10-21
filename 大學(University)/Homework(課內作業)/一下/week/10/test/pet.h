//1083339 隱藏細節的方法 lib靜態函式庫

#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
using namespace std;

class petImp;

class pet
{
public:
	pet() { imp = nullptr; };
	pet(string);
	~pet();
	string Name();
	virtual string makeSound();
protected:
	petImp *imp;
};

class cat:public pet
{
public:
	cat(string);
};

class dog:public pet
{
public:
	dog(string);
};



#endif // !PET_H
