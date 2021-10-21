#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace  std;

struct phonerecord {
	
	//char name[50];
	string name;
	int number;
};
void print(vector<phonerecord> x);
//bool operator<(phonerecord& l, phonerecord& r) {
//	return l.record < r.record;
//}

//bool comp(phonerecord& s1, phonerecord& s2) {
		//return s1.name > s2.name;
	//}
void save( vector<phonerecord> &x)
{
	fstream infile("Pheone.dat", ios::binary | ios::out);
	if (x.size() > 0)
	{
		//for (int i = 0; i < x.size(); i++)
			//infile.write(reinterpret_cast<const char*>(&x), sizeof(x[i]));
		
		for (int i = 0; i < x.size(); i++)
			infile.write(reinterpret_cast<const char*>(&x[i]), sizeof(phonerecord));
	}
}
void open(vector<phonerecord>& x)
{
	fstream infile("Pheone.dat", ios::binary | ios::in);
	if (infile)
	{
		phonerecord temp;
		for(;infile.read(reinterpret_cast<char*>(&temp), sizeof(phonerecord));)
				x.push_back(temp);
		print(x);
	}
	else
	{
		cout << "There is no file: Phones.dat!" << endl;
		save(x);
		cout << "New file is initialized!" << endl;
		cout << endl;
	}
	
}
void print(vector<phonerecord> x)
{
	
	cout << left << setw(19) << "Record#" << setw(19) << "Name" << setw(19) << "PhoneNumber"<<endl;
	for(int i=0;i<x.size();i++)
	cout << left << setw(19) << i+1 << setw(19) << x[i].name << setw(19) <<fixed<<setprecision(2)<< x[i].number<<endl;
	cout << endl;
}
void update(int y,vector<phonerecord>& x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (i+1 == y)
		{
			char p[50] = {};
			int o;
			cout << left << setw(19) << "Record#" << setw(19) << "Name" << setw(19) << "PhoneNumber"<<endl;
			cout << left << setw(19) << i+1 << setw(19) << x[i].name << setw(19) << fixed << setprecision(2) << x[i].number<<endl;
			cout << "Enter the name: ";
			cin >> p;
			cout << "Enter the phone number: ";
			cin >>o;
			//[i].record = y;
			x[i].number = o;
			cout << "Phone Updated.." << endl
				<< "Phones sorted by name." << endl;
			return;
		}
		
	}
	cout << "Cannot Update. The record is empty." << endl;
}
void insert(vector<phonerecord>& x)
{
	phonerecord temp;
	//temp.record = (x.size() + 1);
	cout << "Enter the name: ";
	cin >> temp.name;
	cout << "Enter the phone number: ";
	cin >> temp.number;
	cout << "Phone Inserted."<<endl
		 << "Phones sorted by name."<< endl;
	cout << endl;
	x.push_back(temp);

}
void deleted(int y, vector<phonerecord>& x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (i+1 == y)
		{
			x.erase(x.begin() + i);
			cout << "Phone Delete" << endl;
			return;
		}
	}
	cout << "Cannot delete. The record is empty." << endl;
}
void sort( vector<phonerecord>& x)
{
	//sort(x.begin(), x.end());
	for (int i = 0; i < x.size(); i++)
		for (int j = i; j < x.size(); j++)
		{
			if (x[i].name > x[j].name)
			{
				phonerecord temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	//char hold[15] = {};
	//for (int i = 0; i <x.size(); i++)
				//for (int j = 0; j < x.size(); j++)
			
			//if (strcmp(x[j].name, x[j + 1].name) > 0) {
				//phonerecord temp;
				
				//temp.name =x[j].name;
				//x[j].name = x[j + 1].name;
				//x[j + 1].name=temp.name

				//strcpy(hold, x[j].number);
				//strcpy(x[j].number, x[j + 1].number);
				//strcpy(x[j + 1].number, hold);
			//} 
}
int main()
{ 
	 vector<phonerecord> x;
	 open(x);
	 int y = 0, order = 0;
	 while (true)
	 {
		 cout << "Enter a choice" << endl
			 << "1  List all phones." << endl
			 << "2  Update phone." << endl
			 << "3  Insert phone." << endl
			 << "4  Delete phone." << endl
			 << "5  Save phone." << endl
			 << "6  End program." << endl
			 << "?";
		 cin >> order;
		 switch(order)
		 {
		 case 1:
			 sort(x);
			 print(x);
			 break;
		 case 2:
			 cout << "Update a phone number" << endl
				 << "Enter the phone Record# for update:";
			 cin >> y;
			 update(y,x);
			 sort(x);
			 break;
		 case 3:
			 cout << "Insert a phone number" << endl;
			insert(x);
			sort(x);
			 break;
		 case 4 :
			 cout << "Delete a phone number" << endl
			      << "Enter the phone Record# for deletion:";
			 cin >> y;
			 deleted(y,x);
			 sort(x);
			 break;
		 case 5:
			 save(x);
			 break;
		 case 6:
			 cout << "Bye!" << endl;
			 exit(1);
			 break;
			
		 }


	 }
	

}