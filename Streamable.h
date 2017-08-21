/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef	SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include <iostream>
#include <fstream>

namespace sict
{
	class Streamable {
	public:
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const { return (file); };
		virtual std::fstream& load(std::fstream& file) { return (file); };
		virtual std::ostream& write(std::ostream& os, bool linear) const { return (os); };
		virtual std::istream& read(std::istream& is) { return (is); };
	};

}
#endif
