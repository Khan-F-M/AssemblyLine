// Name: Muhammad F. Khan
// Seneca Student ID: 113-524-201
// Seneca email: mkhan275@myseneca.ca
// Date of completion: 4/3/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

/*All of your source code, including externally linked variables, should 
be in the sdds namespace. Use class declarations in header files wherever appropriate.*/
#include <iostream>
#include "Station.h"

namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		//Instance Variables 
		std::string m_name; //The name of the customer
		std::string m_product; //The name of the product being assembled
		size_t m_cntItem{ 0 }; //A count of the number of items in the customer's order
		Item** m_lstItem{}; /*A dynamically allocated array of pointers. Each element
							of the array points to a dynamically allocated object of type Item*/
		//Class Variable
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&); //The maximum width of a field, used for display purposes

		//Rule of 5
		CustomerOrder(CustomerOrder&); //copy constructor
		CustomerOrder& operator=(CustomerOrder&) = delete; //a CustomerOrder object should not allow copy operations 
		CustomerOrder(CustomerOrder&&) noexcept;   // move constructor
		CustomerOrder& operator=(CustomerOrder&&) noexcept; // move assignment operator
		~CustomerOrder();

		//Rest of the member functions
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif

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
*/