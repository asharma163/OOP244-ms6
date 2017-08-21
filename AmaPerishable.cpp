/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#include <iostream>
#include<fstream>
#include <iomanip>
#include <cstring>
#include "AmaPerishable.h"
#include "AmaProduct.h"
#include "Streamable.h"
#include "general.h"
#include "Date.h"
using namespace std;
namespace sict
{
	AmaPerishable::AmaPerishable()
	{

	}
	const Date& AmaPerishable::expiry()const
	{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date& value)
	{
		expiry_ = value;
	}
	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const
	{
		AmaProduct::store(file, false);
		file << "," << expiry_ << endl;
		if (addNewLine == true)
		{
			file << "\n";
		}
		return file;
	}
	fstream& AmaPerishable::load(fstream& file)
	{
		AmaProduct::load(file);
		expiry_.read(file);
		file.ignore();
		return file;
	}
	ostream& AmaPerishable::write(ostream& ostr, bool linear)const
	{
		AmaProduct::write(ostr, linear);
		if (err_.isClear())
		{
			if (linear == true)
			{
				ostr << expiry();
			}
			else if(linear==false)
			{
				ostr << "\n" << "Expiry date: " << expiry(); 
			}
		}
		return ostr;
	}
	std::istream & AmaPerishable::read(std::istream & istr)
	{
		cin.clear();
		AmaProduct::read(istr);
		if (err_.isClear())
		{
			cin.ignore();
			Date date;
			cout << "Expiry date (YYYY/MM/DD): ";
			expiry(date);
			istr >> date;
			if (date.bad())
			{
				if (date.errCode() == CIN_FAILED)
				{
					err_.message("Invalid Date Entry");
				}
				else if (date.errCode() == YEAR_ERROR)
				{
					err_.message("Invalid Year in Date Entry");
				}
				else if (date.errCode() == MON_ERROR)
				{
					err_.message("Invalid Month in Date Entry");
				}
				else if (date.errCode() == DAY_ERROR)
				{
					err_.message("Invalid Day in Date Entry");
				}
				istr.setstate(ios::failbit);
			}
			else
			{
				expiry(date);
			}
		}
		return istr;
	}
}