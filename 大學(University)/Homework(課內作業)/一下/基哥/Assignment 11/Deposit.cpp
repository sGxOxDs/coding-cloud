#include "Deposit.h"
#include <iostream>
#include <iomanip>
using namespace std;

Deposit::Deposit(int userAccountNumber, vector< Account >& atmAccounts)
    :accountNumber(userAccountNumber), accounts(atmAccounts), amount() {}
void Deposit::execute()
{
    amount = promptForDepositAmount();
    if (amount == 0)
        return;
    Account* temp = getAccount(accountNumber, accounts);
    temp->credit(amount);
    cout << "Please insert a deposit envelope containing $" << setprecision(2) << fixed << amount << " in the deposit slot." << endl;
    cout << "Your envelope has been received." << endl;
    cout << "NOTE : The money deposited will not be available until we" << endl;
    cout << "verify the amount of any enclosed cash, and any enclosed checks clear." << endl;
    cout << endl;
}
Account* Deposit::getAccount(int accountNumber, vector< Account >& accounts)
{
    for (size_t i = 0; i < accounts.size(); i++)
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    return NULL;
}
double Deposit::promptForDepositAmount() const
{
    int temp;
    cout << "Please enter a deposit amount in CENTS(or 0 to cancel) : ";
    cin >> temp;
    return (temp + 0.0) / 100.0;
}