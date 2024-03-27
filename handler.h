#include "printer.h"
#include "standlib.h"
#include <list>
#include <fstream>

// quick make file
int mkfile(std::string filename) {
	std::fstream newfile;
	newfile.open(filename, std::ios::out);

	// if file creation fails returns false
	if (!newfile) {
		print("file creation failed, i hate you");
		return 0;
	}
	newfile.close();
	
	// if succeeds return true
	return 1;
}

// reads file and returns text as string
std::string readfilestring(std::string filename) {
	std::fstream file; 
	file.open(filename, std::ios::in);
	
	// if file doesn't exist this returns empty string
	if (!file) {
		print("file " +filename+ " does not exist");
		return "";
	}

	// main code
	else {
		// makes white space and new line readable
		file >> std::noskipws;

		// text storage and iterator
		std::list<std::string> text;
		char ch; 

		// loops through and adds each character
		while (1) { 
			file >> ch;
			// if end of file stop
			if (file.eof()) {
				break;
			}
			text.push_back(chtostr(ch));
		}
		file.close();

		// concatonates and returns text
		std::string finaltext = ConcatList(text);
		return finaltext;
	}
} 

// this was fun to make...
// reads file and returns list of words
std::list<std::string> readfilelist(std::string filename) {
	std::fstream file;
	file.open(filename, std::ios::in);

	// alerts user if file doesn't exist and returns blank list
	if (!file) {
		print("file " +filename+ " does not exist");
		
		std::list<std::string> killdata;
		return killdata;
	}

	// makes sure white space and new line characters exist
	file >>	std::noskipws;
	
	// words list, word string, iterator char
	std::list<std::string> words;
	std::string word;
	char ch;


	// main code loop
	while (1) {
		file >> ch;

		// stops loop if end of file
		if (file.eof()) {
			break;
		}
		
		// if not space or new line adds iterator char to word
		if ((!isspace(ch)) && (!(ch == '\n'))) {
			word += chtostr(ch);
		}
		// otherwise add word to words and resets word, then adds new line or space
		else {
			words.push_back(word);
			std::string placeholder;
			word = placeholder;
			if (ch == '\n') {
				words.push_back("\n");
			}
			else {
				words.push_back(" ");
			}
		}
	}
	file.close();

	// returns list of words
	return words;
}

// writes string list to file, each index being a line
int writefile(std::list<std::string> inputlist, std::string filename) {
	std::fstream file;
	file.open(filename, std::ios::out);	

	// main code
	for (std::string i : inputlist) {
		file << i;
	}
	file.close();
	
	// if all goes well returns true
	return 1;
}