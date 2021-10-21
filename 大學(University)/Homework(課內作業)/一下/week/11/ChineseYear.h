#ifndef CHINESEYEAR_H
#define CHINESEYEAR_H
#include <iostream>
using namespace std;
class ChineseYear
{
	friend ChineseYear& operator+(int, ChineseYear&);
	friend ostream& operator<<(ostream&, ChineseYear&);
public:
	/*class WrongChineseYear
	{
	public:
		WrongChineseYear() {};
		const char* what() const noexcept { return "wtf 1?"; };
	};
	class WrongGregorianYear
	{
	public:
		WrongGregorianYear() {};
		const char* what() const noexcept { return "wtf 2?"; };
	};*/

	struct WrongChineseYear
	{
		const char* what() const noexcept { return "wtf 1?"; };
	};
	struct WrongGregorianYear
	{
		const char* what() const noexcept { return "wtf 2?"; };
	};
	ChineseYear();
	ChineseYear(int);
	ChineseYear(string);
	~ChineseYear();
	ChineseYear& operator=(ChineseYear&);
	ChineseYear& operator+=(int);
	ChineseYear& operator+(int);
private:
	string gregorian[12] = { "Rat", "Ox","Tiger","Rabbit","Dragon","Snake",
							 "Horse","Goat","Monkey","Rooster","Dog","Pig" };
	int year;
};

#endif // !CHINESEYEAR_H
