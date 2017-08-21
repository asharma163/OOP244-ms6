/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <cstring>
#include "Product.h"
#include "general.h"
#include "Streamable.h"


using namespace std;
namespace sict
{
	Product::Product()
	{
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}
	Product::Product(const char* sku, const char* name, bool tax, double price, int quantity)
	{
		strncpy(sku_, sku, MAX_SKU_LEN);
		int length = strlen(name);
		name_ = new char[length + 1];
		strcpy(name_, name);
		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = quantity;
		taxed_ = tax;
	}
	void Product::m_copyConstructor(const Product& item)                       //copy constructor
	{
		strncpy(sku_, item.sku_, MAX_SKU_LEN);
		int length = strlen(item.name_);
		name_ = new char[length + 1];
		strncpy(name_, item.name_, length + 1);
		price_ = item.price_;
		taxed_ = item.taxed_;
		quantity_ = item.quantity_;
		qtyNeeded_ = item.qtyNeeded_;
	}
	Product::Product(const Product& item)
	{
		m_copyConstructor(item);
	}
	Product::~Product()
	{
		delete[] name_;
		name_ = nullptr;
	}
	Product& Product::operator=(const Product& item)
	{
		if (this != &item && !item.isEmpty())
		{
			m_copyConstructor(item);
		}
		return *this;
	}
	void Product::sku(const char* sku)
	{
		strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';

	}
	void Product::price(const double price)
	{
		price_ = price;
	}
	void Product::name(const char* name)
	{
		int length = strlen(name);
		delete[] name_;
		name_ = new char[length + 1];
		strncpy(name_, name,length);
		name_[length] = '\0';

	}
	void Product::taxed(const bool tax)
	{
		taxed_ = tax;
	}
	void Product::quantity(const int quantity)
	{
		quantity_ = quantity;
	}
	void Product::qtyNeeded(const int qtyNeeded)
	{
		qtyNeeded_ = qtyNeeded;
	}
	const char* Product::sku() const
	{
		return sku_;
	}
	double Product::price() const
	{
		return price_;
	}
	char* Product::name() const
	{
		return name_;
	}
	bool Product::taxed() const
	{
		return taxed_;
	}
	int Product::quantity() const
	{
		return quantity_;
	}
	int Product::qtyNeeded() const
	{
		return qtyNeeded_;
	}
	double Product::cost() const
	{
		if (taxed_)
		{
			return price_ + (price_ * TAX);
		}
		else
		{
			return price_;
		}
	}
	bool Product::isEmpty() const
	{
		if (sku_[0] == '\0' && name_ == nullptr && price_ == 0 && quantity_ == 0&&qtyNeeded_ == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Product::operator==(const char* sku)
	{
		if (strcmp(sku_, sku) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Product::operator+=(const int quantity)
	{
		return quantity_ += quantity;
	}
	int Product::operator-=(const int quantity)
	{
		return quantity_ -= quantity;
	}
	double operator+=(double& d, const Product& I)
	{
		return d += I.quantity() * I.cost();
	}
	std::ostream& operator<<(std::ostream& ostr, const Product& item)
	{
		item.write(ostr, 1);
		return ostr;
	}
	std::istream& operator >> (std::istream& istr, Product& item)
	{
		item.read(istr);
		return istr;
	}
}