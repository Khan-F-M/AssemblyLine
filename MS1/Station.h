// Name: Muhammad F. Khan
// Seneca Student ID: 113-524-201
// Seneca email: mkhan275@myseneca.ca
// Date of completion: 4/3/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

namespace sdds {

	class Station {
		//Instance Variables
		int m_stationId;
		std::string m_nameofitem{};
		std::string m_descofstat{};
		unsigned int m_nextserialnumber;
		unsigned int m_numofstock;

		//Class Variables
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& input);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
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
*/