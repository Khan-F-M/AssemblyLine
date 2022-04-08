// Name: Muhammad F. Khan
// Seneca Student ID: 113-524-201
// Seneca email: mkhan275@myseneca.ca
// Date of completion: 4/8/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	string rtrim(const string& str)
	{
		size_t end = str.find_last_not_of(" \t");
		return (end == std::string::npos) ? "" : str.substr(0, end + 1);
	}


	CustomerOrder::CustomerOrder()
	{
		m_name = "default";
		m_product = "default";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& input)
	{		
		Utilities temp;
		vector<string> tokens;
		size_t next_pos = 0;
		bool more;

		do {

			tokens.push_back(rtrim(temp.extractToken(input, next_pos, more)));

		} while (more);

		m_cntItem = tokens.size() - 2;

		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < tokens.size(); i++) {

			if (i == 0) {
				m_name = tokens[i];
			}
			else if (i == 1) {
				m_product = tokens[i];
			}
			else {
				m_lstItem[i - 2] = new Item(tokens[i]); 
			}
		} 

		if (temp.getFieldWidth() > m_widthField) {
			m_widthField = temp.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&)
	{
		throw("ERROR - COPYING OPERATIONS NOT ALLOWED");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept
	{
		*this = std::move(co);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this  != &src)
		{
			if (m_lstItem) {
				for (size_t i = 0; i < m_cntItem; i++)
					delete m_lstItem[i];
			}

			delete[] m_lstItem;

			m_lstItem = src.m_lstItem;
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;

			src.m_lstItem = nullptr;
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++)
				delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const {
		for(size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled) {
				return true;
			}
		}

		return false;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (unsigned int i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				return m_lstItem[i]->m_isFilled;
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() <= 0) {
					os << "Unable to fill " << m_name << ", ";
					os << m_product;
					os << "[" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;

					os << "Filled ";
					os << m_name << ", ";
					os << m_product;
					os << "[" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber;
			os << setfill(' ') << "] " << setw(m_widthField) << m_lstItem[i]->m_itemName;
			os << "  - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
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
https://www.cplusplus.com/reference/vector/vector/
https://www.geeksforgeeks.org/std-count-cpp-stl/
*/