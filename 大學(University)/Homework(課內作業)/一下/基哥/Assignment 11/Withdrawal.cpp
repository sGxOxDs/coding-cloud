#include "Withdrawal.h"
#include <iostream>
#include <iomanip>
using namespace std;

Withdrawal::Withdrawal(int userAccountNumber, vector< Account >& atmAccounts, int& atmRemainingBills)
    :accountNumber(userAccountNumber), accounts(atmAccounts), amount(), remainingBills(atmRemainingBills) {}
void Withdrawal::execute()
{
	bool candonext = false;
	enum MenuOption { $20 = 1, $40, $60, $100, $200, Cancel };
	Account* account = getAccount(accountNumber, accounts);
	while (!candonext)
	{
		int Selection = displayMenuOfAmounts();
		amount = 0;
		switch (Selection)
		{
			case $20:
				amount = 20;
				break;
			case $40:
				amount = 40;
				break;
			case $60:
				amount = 60;
				break;
			case $100:
				amount = 100;
				break;
			case $200:
				amount = 200;
				break;

			case Cancel:
				return;

			default:
				cout << "\nYou did not enter a valid selection. Try again." << endl;
				break;
		}
		if (account->getAvailableBalance() >= amount && remainingBills >= amount / 20)
		{
			account->debit(amount);
			remainingBills -= amount / 20;
			candonext = true;
		}
		else if (account->getAvailableBalance() < amount)
			cout << "You don't have enough available balance. Try again." << endl;
		else if (remainingBills < amount / 20)
			cout << "ATM don't have enough money. Try again." << endl;
	}
	cout << "Please take your cash from the cash dispenser." << endl;
}
Account* Withdrawal::getAccount(int accountNumber, vector< Account >& accounts)
{
    for (size_t i = 0; i < accounts.size(); i++)
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    return NULL;
}
int Withdrawal::displayMenuOfAmounts() const
{
	int choice;
	cout << "Withdrawal options :" << endl;
	cout << "1 - $20" << endl;
	cout << "2 - $40" << endl;
	cout << "3 - $60" << endl;
	cout << "4 - $100" << endl;
	cout << "5 - $200" << endl;
	cout << "6 - Cancel transaction" << endl << endl;
	cout << "Choose a withdrawal option(1 - 6) : ";
	cin >> choice;
	cout << endl;
	return choice;
}