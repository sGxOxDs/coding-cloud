#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account() :id(0), pin(0), available(0.0), total(0.0) {};
	Account(int, int, double, double);
	~Account() {};
	int Getid() { return id; };
	int Getpin() { return pin; };
	double Getavailable() { return available; };
	double Gettotal() { return total; };
	void Setid(int t_id) { id = t_id; };
	void Setpin(int t_pin) {  pin= t_pin; };
	void Withdraw(int);
	void Deposit(int);

private:
	int id;
	int pin;
	double available;
	double total;
};

#endif // !ACCOUNT_H
