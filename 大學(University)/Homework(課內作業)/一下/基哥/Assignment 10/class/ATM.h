#ifndef ATM_H
#define ATM_H

struct Envelope
{
	int account_id;
	double money_inside;
};

class ATM
{
public:
	ATM() { ATM_id++; };
	~ATM() { ATM_id--; };
	void Reload_ATM() {};
	void Clear_deposit_to_ATM() {};
	void Message_Welcome(Account[], const int);
	void Message_Main(Account&);
	void Message_View(Account&);
	void Message_Withdraw(Account&);
	void Message_Deposit(Account&);
	bool Check_Account_Exist(Account&, Account[], const int);

private:
	static unsigned int ATM_id;
	unsigned int each_day_loaded = 500;
	vector<Envelope> deposit_to_ATM;
};

#endif // !ATM_H
