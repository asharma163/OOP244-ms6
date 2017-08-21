/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_DATE_H__                  //header guards.
#define SICT_DATE_H__
#include<iostream>
namespace sict {                      // namespace declared.
#define NO_ERROR   0                  //////////////////
#define CIN_FAILED 1                  //              //    
#define YEAR_ERROR 2                  //  ERROR CODES //
#define MON_ERROR  3                  ////////////////// 
#define DAY_ERROR  4                  

	class Date {
	private:
		int year_;
		int mon_;
		int day_;
		int date_only_;
		int readErrorCode_;
		int value()const;
		void errCode(int errorCode);
	public:
		Date();                                                // default constructor.
		Date(int, int, int);
		bool operator==(const Date& D) const;                  ///////////////////////////////////////////////// 
		bool operator!=(const Date& D) const;                  //                                             //
		bool operator<(const Date& D) const;                   //      OPERATOR OVERLOADING..                                       // 
		bool operator>(const Date& D) const;                   //                                             //
		bool operator<=(const Date& D) const;                  //                                             //
		bool operator>=(const Date& D) const;                  /////////////////////////////////////////////////
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		int mdays()const;
	};
	std::istream& operator >> (std::istream&, Date&);               //  HELPER FUNCTION
	std::ostream& operator<<(std::ostream&, const Date&);           //  HELPER FUNCTION




}
#endif