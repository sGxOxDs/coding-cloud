#include "loading.h"

unsigned int ATM::ATM_id = 0;
void ATM::Message_Welcome(Account account_data[], const int account_data_size)
{
	int t_id,t_pin;
	Account temp;
	cout << "Welcome!" << endl << endl;
	cout << "Please enter your account number : ";
	cin >> t_id;
	cout << "Enter your PIN : ";
	cin >> t_pin;
	temp.Setid(t_id);
	temp.Setpin(t_pin);

	while (!Check_Account_Exist(temp, account_data, account_data_size))
	{
		cout << "Try again!" << endl << endl;
		cout << "Please enter your account number : ";
		cin >> t_id;
		cout << "Enter your PIN : ";
		cin >> t_pin;
		temp.Setid(t_id);
		temp.Setpin(t_pin);
	}

	Message_Main(temp);
}
void ATM::Message_Main(Account& account)
{
	int choice;
	while (true)
	{
		cout << "Main menu :" << endl;
		cout << "1 - View my balance" << endl;
		cout << "2 - Withdraw cash" << endl;
		cout << "3 - Deposit funds" << endl;
		cout << "4 - Exit" << endl << endl;
		cout << "Enter a choice :";
		cin >> choice;
		cout << endl;
		if (choice == 1)
			Message_View(account);
		else if (choice == 2)
			Message_Withdraw(account);
		else if (choice == 3)
			Message_Deposit(account);
		else if (choice == 4)
		{
			cout << "Exiting the system..." << endl;
			cout << "Thank you!Goodbye!" << endl << endl;
			break;
		}
		else
			cout << "Try again!" << endl << endl;
	}
}
void ATM::Message_View(Account& account)
{
	cout << "Balance Information :" << setprecision(2) << fixed << endl;
	cout << "- Available balance : " << account.Getavailable() << endl;
	cout << "- Total balance : " << account.Gettotal() << endl << endl;
}
void ATM::Message_Withdraw(Account& account)
{
	int choice;
	while (true)
	{
		cout << "Withdrawal options :" << endl;
		if (account.Getavailable() >= 20)
			cout << "1 - $20" << endl;
		if (account.Getavailable() >= 40)
			cout << "2 - $40" << endl;
		if (account.Getavailable() >= 60)
			cout << "3 - $60" << endl;
		if (account.Getavailable() >= 100)
			cout << "4 - $100" << endl;
		if (account.Getavailable() >= 200)
			cout << "5 - $200" << endl;
		cout << "6 - Cancel transaction" << endl << endl;
		cout << "Choose a withdrawal option(1 - 6) : ";
		cin >> choice;
		cout << endl;
		if (choice == 1 && account.Getavailable() >= 20 && each_day_loaded >=1)
		{
			account.Withdraw(20);
			each_day_loaded -= 1;
			cout << "Please take your cash from the cash dispenser." << endl;
			break;
		}
		else if (choice == 2 && account.Getavailable() >= 40 && each_day_loaded >= 2)
		{
			account.Withdraw(40);
			each_day_loaded -= 2;
			cout << "Please take your cash from the cash dispenser." << endl;
			break;
		}
		else if (choice == 3 && account.Getavailable() >= 60 && each_day_loaded >= 3)
		{
			account.Withdraw(60);
			each_day_loaded -= 3;
			cout << "Please take your cash from the cash dispenser." << endl;
			break;
		}
		else if (choice == 4 && account.Getavailable() >= 100 && each_day_loaded >= 5)
		{
			account.Withdraw(100);
			each_day_loaded -= 5;
			cout << "Please take your cash from the cash dispenser." << endl;
			break;
		}
		else if (choice == 5 && account.Getavailable() >= 200 && each_day_loaded >= 10)
		{
			account.Withdraw(200);
			each_day_loaded -= 10;
			cout << "Please take your cash from the cash dispenser." << endl;
			break;
		}
		else if (choice == 6)
		{
			break;
		}
		else
		{
			cout << "Error choice!" << endl;
			if (account.Getavailable() < 200)
				cout << "May your available isn't enough " << endl;
			if (each_day_loaded < 10)
				cout << "May this ATM haven't enough money" << endl;
			cout << "Try again!" << endl;
			cout << endl;
		}

	}
}
void ATM::Message_Deposit(Account& account)
{
	int deposit;
	cout << "Please enter a deposit amount in CENTS(or 0 to cancel) : ";
	cin >> deposit;
	if (deposit == 0)
		return;
	else
	{
		Envelope temp;
		temp.account_id = account.Getid();
		temp.money_inside = (deposit + 0.0) / 100.0;
		deposit_to_ATM.push_back(temp);
		account.Deposit(deposit);
	}
	cout << "Please insert a deposit envelope containing $10.00 in the deposit slot." << endl;
	cout << "Your envelope has been received." << endl;
	cout << "NOTE : The money deposited will not be available until we" << endl;
	cout << "verify the amount of any enclosed cash, and any enclosed checks clear." << endl;
	cout << endl;

}
bool ATM::Check_Account_Exist(Account& account, Account account_data[], const int account_data_size)
{
	for (int i = 0; i < account_data_size; i++)
	{
		if (account.Getid() == account_data[i].Getid() && account.Getpin() == account_data[i].Getpin())
		{
			account = account_data[i];
			return true;
		}
	}
	return false;
}