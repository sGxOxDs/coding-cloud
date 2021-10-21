#include "ChineseYear.h"


ChineseYear::ChineseYear()
{
	year = 2020;
}
ChineseYear::ChineseYear(int t_year)
{
	if (t_year < 1990)
	{
		throw WrongGregorianYear();
	}
	year = t_year;
	
}
ChineseYear::ChineseYear(string t_gregorian)
{
	for (int i = 2020; i > 2020-12; i--)
		if (gregorian[(i+8)%12] == t_gregorian)
		{
			year = i;
			return;
		}
	throw WrongChineseYear();
}
ChineseYear::~ChineseYear()
{

}
ChineseYear& ChineseYear::operator=(ChineseYear& right)
{
	year = right.year;
	return *this;
}
ChineseYear& ChineseYear:: operator+= (int add)
{
	year += add;
	return *this;
}
ChineseYear& ChineseYear::operator+(int add)
{
	year += add;
	return *this;
}

ChineseYear& operator+(int left, ChineseYear& right)
{
	right.year += left;
	return right;
}
ostream& operator<<(ostream& output, ChineseYear& right)
{
	output << right.gregorian[(right.year + 8) % 12] << " " << right.year << "-" << right.year + 1;
	return output;
}