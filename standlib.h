#include <iostream>
#include <list>

// converts char to string
std::string chtostr(char x) {
	std::string s(1, x);
	return s;
} 

// concatonates list to string
std::string ConcatList(std::list<std::string> inputlist) {
	std::string fulltext = "";
	for (std::string i : inputlist) {
		fulltext += i;
	}
	return fulltext;
} 