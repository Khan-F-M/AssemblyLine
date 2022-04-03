// Name: Muhammad F. Khan
// Seneca Student ID: 113-524-201
// Seneca email: mkhan275@myseneca.ca
// Date of completion: 4/3/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <limits.h>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	size_t Station::m_widthField = 0; //the maximum number of characters required to print to the screen the item name for any object of type Station
	size_t Station::id_generator = 0; //The current value of the id_generator is stored in that instance, and id_generator is incremented

	Station::Station(const string& input) {

		Utilities temp;
		bool more; // if there are more tokens in the input string
		size_t pos = 0; // position of the next token in the input string
		m_stationId = id_generator+=1;

		m_nameofitem = temp.extractToken(input, pos, more);
		m_nextserialnumber = stoi(temp.extractToken(input, pos, more));
		m_numofstock = stoi(temp.extractToken(input, pos, more));

		//Before extracting description, it updates Station::m_widthField
		m_widthField = max(temp.getFieldWidth(), m_widthField); //updates Station::m_widthField to the maximum value of Station::m_widthField and Utilities::m_widthField

		m_descofstat = temp.extractToken(input, pos, more);
	}

	const string& Station::getItemName() const {
		return m_nameofitem;
	}

	size_t Station::getNextSerialNumber() {
		return m_nextserialnumber++;

	}

	size_t Station::getQuantity() const {
		return m_numofstock;
	}

	void Station::updateQuantity() {

		if (m_numofstock < 0) {
			m_numofstock = 0;
		}

		else m_numofstock--;
	}

	void Station::display(std::ostream& os, bool full) const {

		os << setfill('0') << setw(3) << right << m_stationId << " | ";
		os << setw(m_widthField) << setfill(' ') << left << m_nameofitem << " | ";
		os << setfill('0') << setw(6) << right << m_nextserialnumber << " | ";

		if (full) {
			os << right << setw(4) << setfill(' ') << m_numofstock << " | ";
			os << left << m_descofstat << endl;
		}
		else {
			os << endl;
		}
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