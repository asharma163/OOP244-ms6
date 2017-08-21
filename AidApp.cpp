/* NAME- ANSHUL SHARMA
   STUDENT ID-136530169
   SENECA MAIL- asharma163@myseneca.ca
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include "AidApp.h"
using namespace std;
namespace sict {
	AidApp::AidApp(const char* filename) {
		strcpy(filename_, "");
		strcpy(filename_, filename);
		for (int j = 0; j < MAX_NO_RECS; j++) {
			product_[j] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}
	void AidApp::pause()const {
		cout << "\nPress Enter to continue...\n";
		cin.ignore();
	}
	int AidApp::menu() {
		unsigned int y;
		cout << "Disaster Aid Supply Management Program" << endl
			<< "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "0- Exit program" << endl
			<< "> ";
		cin >> y;
		return y;
		cin.ignore();
	}
	void AidApp::loadRecs() {
		char g;
		int m_readIndex = 0;                             
		datafile_.open(filename_, ios::in);
		if (datafile_.fail()) {
			
			datafile_.close();
			datafile_.open(filename_, ios::out);
			datafile_.close();
		}
		else {
			while (true)
			{
				datafile_ >> g;
				if (datafile_.fail()) {
					break;
				}
				datafile_.ignore();
				Product* p = (Product*)m_readIndex;
				if (g == 'N') {
					p = new AmaProduct();                       //create non-perishable product.
				}
				else if (g == 'P') {
					p = new AmaPerishable();                    // create perishable product.

				}
				if (p != ((Product*)m_readIndex)) {
					p->load(datafile_);
					product_[m_readIndex++] = p;
				
				}
				datafile_.clear();
			}
		}
		noOfProducts_ = m_readIndex;
		datafile_.clear();
		datafile_.close();
	}
	void AidApp::saveRecs() {
		datafile_.open(filename_, ios::out);
		for (int j = 0; j <= noOfProducts_; j++) {
			product_[j]->store(datafile_);
		}
		datafile_.clear();
		datafile_.close();
	}

	void AidApp::listProducts() const {
		int c = 0;
		double total = 0;


		cout << "\n" <<
			" Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl <<
			"-----|--------|--------------------|-------|----|----------|----|----------" << endl;

		do {
			cout << setfill(' ') << right << setw(4) << (c + 1) << " | " << left << *product_[c] << endl;
			total += *product_[c];
			if (c == 10) {
				pause();
			}
		} while (++c < noOfProducts_);

		cout <<
			"---------------------------------------------------------------------------" << endl <<
			"Total cost of support: $" << fixed << setprecision(2) << showpoint << total << endl;

	}
	int AidApp::SearchProducts(const char * sku) const {
		int j = 0; int m = 0;
		while (m == 0 && j < noOfProducts_) {
			if (*product_[j] == sku) {
				m = -1;
				j--;
			}
			j++;
		}
		if (m != -1) {
			j = -1;
		}
		return j;
	}
	void AidApp::addQty(const char* sku) {
		cin.clear();
		cin.ignore();
		int m_check = SearchProducts(sku);
		Product* p;
		int b = 0;
		if (m_check == -1) {
			cout << "Not found!" << endl;
		}
		else {
			p = product_[m_check];
			p->write(cout, false);
			cout << endl << "\nPlease enter the number of purchased items: ";
			cin >> b;
			if (cin.fail()) {
				cout << "Invalid Quantity value!" << endl;
			}
			else {
				cin.ignore();
				int l = p->qtyNeeded() - p->quantity();
				if (b <= l) {
					*p += b;
				}
				else {
					*p += l;
					cout << "Too much products, only " << l << " is needed, please return the extra " << (b + l) << " items." << endl;
				}
				saveRecs();
				cout << "\nUpdated!\n" << endl;
			}
		}
	}
	void AidApp::addProduct(bool isPerishable) {
		Product* p;
		if (isPerishable) { p = new AmaPerishable(); }
		else { p = new AmaProduct(); }
		cin >> *p;
		if (cin.fail()) {
			p->write(cout, false);
		}
		else {
			datafile_.open(filename_, ios::out | ios::app);
			p->store(datafile_);
			datafile_.close();
			cout << "\nProduct added\n" << endl;
		}
	}
	int sict::AidApp::run()
	{
		int flag = 0;
		char m_sku[MAX_SKU_LEN];
		while (flag == 0) {
			int user_selection = menu();
			switch (user_selection)
			{
			case 0:
			{
				flag = -1;
				break;
			}
			case 1:
			{
				listProducts();
				pause();
				cin.ignore();
				break;
			}
			case 2:
			{
				cout << "\nPlease enter the SKU: ";
				cin >> m_sku;

				int x = SearchProducts(m_sku);
				cout << "\n";
				if (x != -1) {
					Product* p;
					p = product_[x];
					p->write(cout, false);
				}
				else
					cout << "NOT FOUND" << endl;
				cout << "\n";
				pause();
				cin.ignore();
				break;
			}
			case 3:
			{
				cout << "\n";
				addProduct(false);
				loadRecs();
				cin.ignore();
				break;
			}
			case 4:
			{
				cout << "\n";
				addProduct(true);
				loadRecs();
				cin.ignore();
				break;
			}
			case 5:
			{
				cin.ignore();
				cout << "\nPlease enter the SKU: ";
				cin >> m_sku;
				cout << "\n";
				addQty(m_sku);
				break;
			}

			default:
				cout << " == Invalid Selection, try again. == =" << endl;
				break;
			}
			cin.clear();
		}
		cout << "\nGoodbye!!" << endl;
		return 0;
	}
		
}
	
