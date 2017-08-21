/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include<iostream>
#include<fstream>
#include"Product.h"
#include"ErrorMessage.h"
using namespace std;
namespace sict {
	class AmaProduct : public Product
	{
	private:
		char fileTag_;
		char unit_[11];
	protected:
		ErrorMessage err_;
	public:
		AmaProduct(const char m_fileTag = 'N');
		const char* unit()const;
		void unit(const char* value);
		fstream& store(fstream& file, bool addNewLine = true)const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear = true)const;
		istream& read(istream& istr);
	};
}
#endif
