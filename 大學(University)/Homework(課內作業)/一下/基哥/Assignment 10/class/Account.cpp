#include "loading.h"

Account::Account(int t_id, int t_pin, double t_available, double t_total)
{
	id = t_id;
	pin = t_pin;
	available = t_available;
	total = t_total;
}
void Account::Withdraw(int withdraw)
{
	available -= withdraw;
	total -= withdraw;
}
void Account::Deposit(int deposit)
{
	total += (deposit + 0.0) / 100.0;
}