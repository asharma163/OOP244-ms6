/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include "general.h"
#include "Streamable.h"
namespace sict
{
	class Product : public Streamable
	{
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Product();
		Product(const char*, const char*, bool tax = true, double = 0.0, int = 0);
		void m_copyConstructor(const Product&);
		Product& operator=(const Product&);
		Product(const Product&);
		virtual ~Product();
		void sku(const char*);
		void price(const double);
		void name(const char*);
		void taxed(const bool);
		void quantity(const int);
		void qtyNeeded(const int);
		const char* sku() const;
		double price() const;
		char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);
	};
	double operator+=(double& d, const Product& I);
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator >> (std::istream&, Product&);
}
#endif