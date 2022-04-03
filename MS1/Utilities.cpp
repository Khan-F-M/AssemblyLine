// Name: Muhammad F. Khan
// Seneca Student ID: 113-524-201
// Seneca email: mkhan275@myseneca.ca
// Date of completion: 4/2/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds {

	char Utilities::m_delimiter;

	string Utilities::ltrim(string& str) //Removes the leading space infront of Station1 strings
	{
		size_t space = str.find_first_not_of(" \t");

		if (space == string::npos) {
			return "";
		}
		else {
			return str.substr(space);
		}
	}


	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		
		size_t posofnewd = str.find(getDelimiter(), next_pos);

		string token = str.substr(next_pos, posofnewd - next_pos); //whatever is in between next_pos and (posofnewd - new_pos) will be copied into the substring

		token = ltrim(token);

		if (posofnewd == next_pos)
		{
			more = false;
			throw string("EXCEPTION - NO TOKEN BETWEEN DELIMITERS"); //reports an exception if a delimiter is found at next_pos
		}

		next_pos = posofnewd + 1;
		more = posofnewd != string::npos;

		if (m_widthField < token.size()) {
			setFieldWidth(token.size());
		}

		return token;

	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}



//Sources:
/*
https://ict.senecacollege.ca/~oop345/pages/content/funda.html
https://ict.senecacollege.ca/~oop345/pages/content/compt.html
https://www.geeksforgeeks.org/difference-between-instance-variable-and-class-variable/
https://www.cplusplus.com/reference/string/string/find/
https://www.cplusplus.com/reference/string/string/substr/
https://github.com/Khan-F-M
https://www.cplusplus.com/reference/string/stoi/
https://www.cplusplus.com/reference/algorithm/max/
https://stackoverflow.com/questions/1855459/maximum-value-of-int
https://docs.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-170
https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
https://www.cplusplus.com/reference/string/string/find_first_not_of/
http://www.cplusplus.com/forum/general/115700/
https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/#:~:text=We%20can%20use%20a%20combination,functions%20to%20trim%20the%20string.
https://stackoverflow.com/questions/46514209/c-how-to-use-find-first-not-of
*/