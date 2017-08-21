/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#include "Date.h"
#include "general.h"
namespace sict {                                       //namespace declared

	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}
	Date::Date()                                 //constructor
	{
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}
	Date::Date(int year, int month, int day)
	{
		year_ = year;
		mon_ = month;
		day_ = day;
		readErrorCode_ = NO_ERROR;
	}

	bool Date::operator==(const Date& D) const
	{
		if (this->value() == D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator!=(const Date& D) const
	{
		if (this->value() != D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator<(const Date& D) const
	{
		if (this->value() < D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator>(const Date& D) const
	{
		if (this->value() > D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(const Date& D) const
	{
		if (this->value() <= D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator>=(const Date& D) const
	{
		if (this->value() >= D.value())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::bad() const
	{
		if (readErrorCode_ != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Date::errCode(int errorCode)
	{
		readErrorCode_ = errorCode;
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
	int Date::errCode() const
	{
		return readErrorCode_;
	}

	std::istream& Date::read(std::istream& istr)
	{
		istr >> year_;
		istr.ignore();
		istr >> mon_;
		istr.ignore();
		istr >> day_;
		if (istr.fail())
		{
			readErrorCode_ = CIN_FAILED;
		}
		else
		{
			if (year_ >= MIN_YEAR && year_ <= MAX_YEAR)
			{
				if (mon_ >= 1 && mon_ <= 12)
				{
					if (day_ <= mdays() && day_ >= 1)
					{
						errCode(NO_ERROR);
					}
					else
					{
						errCode(DAY_ERROR);
					}
				}
				else
				{
					errCode(MON_ERROR);
				}
			}
			else errCode(YEAR_ERROR);
		}
		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr) const
	{
		ostr << year_ << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << mon_;
		ostr << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << day_;
		return ostr;

	}
	std::istream& operator >> (std::istream& istr, Date& D)
	{
		D.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& istr, const Date& D)
	{
		D.write(istr);
		return istr;
	}
}
