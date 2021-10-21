#pragma once
#ifndef ABILITY_H
#define ABILITY_H

class Ability
{
public:
	Ability() {};
	~Ability() {};
	virtual bool use(Pet& left); //Avoid
	virtual void use(Pet&, Pet&) {}; //another
	virtual void use(Pet&, Pet&, int&); //Double Attack
	virtual void use(Pet&, Pet& ,double) {}; //Counter_Attack
	virtual string ability_name() { return "No Ability"; };
	void allreset();
protected:
	bool used_all = false;
};

class Heal :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Burning :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Counter_Attack :public Ability
{
public:
	void use(Pet&, Pet&, double);
	string ability_name();
private:

};

class Immunology :public Ability //ªÅ
{
public:
//	void use(Pet&, Pet&) {};
	string ability_name();
//private:

};

class Leech_Life :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Avoid :public Ability
{
public:
	bool use(Pet& left);
	string ability_name();
private:

};

class Double_Attack :public Ability
{
public:
	void use(Pet&, Pet&, int&);
	string ability_name();
private:

};

class Poison :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Lower_Speed :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Rock_Skin :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Lower_Defence :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};

class Lower_Attack :public Ability
{
public:
	void use(Pet&, Pet&);
	string ability_name();
private:

};
#endif // !ABILITY_H
