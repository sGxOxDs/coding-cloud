#include "pet.h"

class petImp
{
public:
	petImp(){};
	petImp(string);
	string Name();
	virtual string makeSound() { return ""; };
protected:
	string name;

};

class catImp:public petImp
{
public:
	catImp(string);
	string makeSound();
};

class dogImp:public petImp
{
public:
	dogImp(string);
	string makeSound();
};

pet::pet(string na)
{
	imp = new petImp(na);
}
pet::~pet()
{
	if (imp != nullptr)
		delete imp;
}
string pet::Name()
{
	return imp->Name();
}
string pet::makeSound()
{
	return imp->makeSound();
}

cat::cat(string na)
{
	imp = new catImp(na);
}
dog::dog(string na)
{
	imp = new dogImp(na);
}

petImp::petImp(string na)
{
	name = na;
}
string petImp::Name()
{
	return name;
}

catImp::catImp(string na)
{
	name = na;
}
string catImp::makeSound()
{
	string temp = "miau";
	return temp;
}

dogImp::dogImp(string na)
{
	name = na;
}
string dogImp::makeSound()
{
	string temp = "won";
	return temp;
}