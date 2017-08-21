/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include<limits>
#include "AmaProduct.h"
#include "ErrorMessage.h"
using namespace std;
namespace sict                                                   // NAMESPACE DECLARED
{
	AmaProduct::AmaProduct(const char m_fileTag)
	{
		if (m_fileTag != '\0')
		{
			fileTag_ = m_fileTag;
		}
	}
	const char* AmaProduct::unit() const
	{
		return unit_;
	}
	void AmaProduct::unit(const char* value)
	{
		strncpy(unit_, value, 10);
		unit_[10] = '\0';
	}
	fstream& AmaProduct::store(fstream& file, bool addNewLine)const
	{
		file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit() << "," << qtyNeeded();
		if (addNewLine == true)
		{
			file << "\n";
		}
		return file;
	}
	fstream& AmaProduct::load(fstream& file)
	{
		char p[MAX_SKU_LEN];
		char j[256];
		char q; char w;
		int m;
		char v;
		char t[11] = { 0 };
		for (int i = 0; i < 11; i++)
			t[i] = '\0';
		double d;
		int i;
		file.getline(p, MAX_SKU_LEN , ',');
		sku(p);
		file.getline(j, 256, ',');
		name(j);
		file >> d>>v;
		price(d);
		file >> m >> w;
		taxed(m);
		file >> i >> q;
		quantity(i);
		file.getline(t, 9, ',');
		unit(t);
		file >> i;
		qtyNeeded(i);
		file.ignore();
		return file;
	}
	ostream& AmaProduct::write(std::ostream& os, bool linear) const
	{
		if (err_.isClear() == false)
		{
			os << err_.message();
		}
		else
		{
			if (linear == true)
			{
				os.setf(ios::fixed);
				os.setf(ios::left);
				os.width(MAX_SKU_LEN);
				os << setfill(' ') << sku() << "|";
				os.width(20);
				os.setf(ios::left);
				os << name() << "|";
				os.unsetf(ios::left);
				os.setf(ios::fixed);
				os.precision(2);
				os.width(7);
				os << cost() << "|";
				os.precision(6);
				os.width(4);
				os << quantity() << "|";
				os.width(10);
				os.setf(ios::left);
				os << unit_ << "|";
				os.unsetf(ios::left);
				os.width(4);
				os << qtyNeeded() << "|";
				os.unsetf(ios::fixed);
			}
			else
			{
				os << "Sku: " << sku() << endl;
				os.setf(ios::fixed);
				os.precision(2);
				os << "Name: " << name() << endl << "Price: " << price() << endl << "Price after tax: ";
				if (taxed())
				{
					os << cost() << endl;
				}
				else if (!taxed())
					os << "N/A" << endl;
				os << "Quantity On Hand: " << quantity() << " ";
				for (int i = 0; i < 11; i++)
				{
					if (unit_[i] != '\0')
						os << unit_[i];
				}
				os << "\nQuantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}
	istream& AmaProduct::read(istream& is)
	{
		err_.clear();
		cin.clear();
		cin.ignore();
		char s[MAX_SKU_LEN];
		char l[256];
		double d;
		int i;
		int k = 0;
		char v[11];
		for (int i = 0; i < 11; i++)
			v[i] = '\0';
		char z;
		if (is.fail() == false)
		{
			err_.clear();
			cout << "Sku: ";
			is >> s;
			sku(s);

			cin.ignore();
			cout << "Name: ";
			is.getline(l, 256);
			name(l); 
			;
			cout << "Unit: ";
			is >> noskipws >> v;
			unit(v);
		
			cin.ignore();
			cout << "Taxed? (y/n): ";
			is >> z;
			if (z == 'Y' || z == 'y' || z == 'N' || z == 'n')
			{
				if (z == 'Y' || z == 'y')
				{
					taxed(true);
				}
				else
				{
					taxed(false);
				}
			}
			else
			{
				err_.message("Only (Y)es or (N)o are acceptable");
				
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				is.setstate(ios::failbit);
				k = 1;
			}
			if (k != 1)
			{
				
				cin.ignore();
				cout << "Price: ";
				is >> d;
				if (cin.fail())
				{
					err_.message("Invalid Price Entry");
					is.setstate(ios::failbit);
				}
				else
				{
					price(d);
				}
			}
			if (err_.isClear())
			{
				
				cin.ignore();
				cout << "Quantity On hand: ";
				is >> i;
				if (cin.fail())
				{
					err_.message("Invalid Quantity Entry");
					is.setstate(ios::failbit);
				}
				else
				{
					quantity(i);
				}
			}
			if (err_.isClear())
			{
				
				cin.ignore();
				cout << "Quantity Needed: ";
				is >> i;
				if (cin.fail())
				{
					
					err_.message("Invalid Quantity Needed Entry");
					is.setstate(ios::failbit);
				}
				else
				{
					qtyNeeded(i);
				}
			}
		}
		return is;
	}
}