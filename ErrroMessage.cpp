/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorMessage.h"
using namespace std;
namespace sict
{
	ErrorMessage::ErrorMessage()
	{
		message_ = nullptr;
	}
	ErrorMessage::ErrorMessage(const char* errorMessage)
	{
		message_ = nullptr;
		message(errorMessage);
	}
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage)
	{
		clear();
		message(errorMessage);
		return *this;
	}
	ErrorMessage::~ErrorMessage()                   //deconstructor.
	{
		delete[] message_;
	}
	void ErrorMessage::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}
	bool ErrorMessage::isClear() const
	{
		if (message_ == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ErrorMessage::message(const char* value)
	{
		delete[] message_;
		int length = strlen(value);
		message_ = new char[length + 1];
		strcpy(message_, value);
	}
	const char* ErrorMessage::message() const
	{
		return message_;
	}
	ErrorMessage::operator bool() const
	{
		return isClear();
	}
	ostream& operator<<(ostream& os, ErrorMessage& err)
	{
		if (err.ErrorMessage::isClear())
		{
			return os;
		}
		else
		{
			int length = strlen(err.message());
			const char* message = err.message();
			for (int i = 0; i < length; i++)
			{
				os << message[i];
			}
			return os;
		}
	}
}