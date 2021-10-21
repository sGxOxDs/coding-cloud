#include "class/loading.h"

int account_size = 2;
Account account[2] = { {12345,54321,1000.0,1200.0} ,
					   {98765,56789,200.0,200.0} };
ATM atm;
int main()
{
	while (true)
	{
		atm.Message_Welcome(account, account_size);
	}
	return 0;
}