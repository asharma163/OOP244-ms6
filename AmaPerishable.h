/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__

#include<iostream>
#include<fstream>
#include "ErrorMessage.h"
#include "Product.h"
#include "AmaProduct.h"
#include "Date.h"

using namespace std;
namespace sict
{
	class AmaPerishable :public AmaProduct
	{
	private:
		Date expiry_;
	public:
		AmaPerishable();
		const Date& expiry()const;
		void expiry(const Date &value);
		fstream& store(fstream& file, bool addNewLine = true)const;
		fstream& load(fstream& file);
		ostream& write(ostream& ostr, bool linear)const;
		istream& read(istream& istr);
	};
}
#endif 