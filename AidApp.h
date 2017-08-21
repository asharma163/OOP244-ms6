/* NAME- ANSHUL SHARMA
STUDENT ID-136530169
SENECA MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_AIDAPP_H_
#define SICT_AIDAPP_H_
#include "AmaProduct.h"
#include "AmaPerishable.h"
using namespace std;
namespace sict {
	class AidApp {
	private:
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		fstream datafile_;
		int noOfProducts_;
	public:
		AidApp(const char* filename);
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);
		int run();
	};
}
#endif