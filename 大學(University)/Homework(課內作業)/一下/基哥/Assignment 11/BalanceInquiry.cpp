#include "BalanceInquiry.h"
#include <iostream>
#include <iomanip>
using namespace std;

BalanceInquiry::BalanceInquiry(int userAccountNumber, vector< Account >& atmAccounts)
    :accountNumber(userAccountNumber), accounts(atmAccounts){}
void BalanceInquiry::execute()
{
    Account* temp = getAccount(accountNumber, accounts);
    cout << "Balance Information :" << setprecision(2) << fixed << endl;
    cout << "- Available balance : " << temp->getAvailableBalance() << endl;
    cout << "- Total balance : " << temp->getTotalBalance() << endl << endl;
}
Account* BalanceInquiry::getAccount(int accountNumber, vector< Account >& accounts)
{
    for (size_t i = 0; i < accounts.size(); i++)
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    return NULL;
}