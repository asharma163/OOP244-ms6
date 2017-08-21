/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_ERRORMESSAGE_H_
#define SICT_ERRORMESSAGE_H_
#include <iostream>
namespace sict
{
	class ErrorMessage
	{
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char*);
		ErrorMessage(const ErrorMessage&) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* value);
		const char* message() const;
		operator bool() const;
	};
	std::ostream& operator<<(std::ostream&, ErrorMessage&);
}

#endif