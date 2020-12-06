#ifndef MAGNIFIER_H
#define MAGNIFIER_H

constexpr unsigned short LEN = 7;

#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
#include <array>
#include <list>
#include <map>


// ============================================================================

class magnifier{
	private:
		
		std::string word, bigWord[LEN];
		std::map <char, std::array <std::string, LEN>> letter;
		unsigned short length;

		void input();
		void regulate();
		void present();
		void clrscr() {system("@cls||clear");}
	public:
		char element;
		
		// Constructor
		magnifier();

		// the main method
		void process();
};

// ============================================================================

magnifier :: magnifier(){

	letter['A'] = {" @@@@@ ","@     @","@     @","@     @","@@@@@@@","@     @","@     @"};
	letter['B'] = {"@@@@@@@","@     @","@     @","@@@@@@ ","@     @","@     @","@@@@@@ "};
	letter['C'] = {" @@@@@ ","@     @","@      ","@      ","@      ","@     @"," @@@@@ "};
	letter['D'] = {"@@@@@@ ","@     @","@     @","@     @","@     @","@     @","@@@@@@ "};
	letter['E'] = {"@@@@@@@","@      ","@      ","@@@@@  ","@      ","@      ","@@@@@@@"};
	letter['F'] = {"@@@@@@@","@      ","@      ","@@@@@  ","@      ","@      ","@      "};
	letter['G'] = {" @@@@@ ","@     @","@      ","@   @@@","@   @ @","@     @"," @@@@@ "};
	letter['H'] = {"@     @","@     @","@     @","@@@@@@@","@     @","@     @","@     @"};
	letter['I'] = {"@@@@@@@","   @   ","   @   ","   @   ","   @   ","   @   ","@@@@@@@"};
	letter['J'] = {"@@@@@@@","      @","      @","      @","@     @","@     @"," @@@@@ "};
	letter['K'] = {"@    @@","@   @  ","@  @   ","@@@    ","@  @   ","@   @  ","@    @@"};
	letter['L'] = {"@      ","@      ","@      ","@      ","@      ","@      ","@@@@@@@"};
	letter['M'] = {"@     @","@@   @@","@ @ @ @","@  @  @","@  @  @","@     @","@     @"};
	letter['N'] = {"@     @","@@    @","@ @   @","@  @  @","@   @ @","@    @@","@     @"};
	letter['O'] = {" @@@@@ ","@     @","@     @","@     @","@     @","@     @"," @@@@@ "};
	letter['P'] = {"@@@@@@ ","@     @","@     @","@@@@@@ ","@      ","@      ","@      "};
	letter['Q'] = {" @@@@@ ","@     @","@     @","@  @  @","@  @@ @","@    @@"," @@@@@@"};
	letter['R'] = {"@@@@@@ ","@     @","@     @","@@@@@@ ","@  @   ","@   @  ","@    @@"};
	letter['S'] = {" @@@@@ ","@     @","@      "," @@@@@ ","      @","@     @"," @@@@@ "};
	letter['T'] = {"@@@@@@@","   @   ","   @   ","   @   ","   @   ","   @   ","   @   "};
	letter['U'] = {"@     @","@     @","@     @","@     @","@     @","@     @"," @@@@@ "};
	letter['V'] = {"@     @","@     @","@     @","@     @"," @   @ ","  @ @  ","   @   "};
	letter['W'] = {"@     @","@     @","@  @  @","@  @  @","@ @ @ @","@@   @@","@     @"};
	letter['X'] = {"@     @"," @   @ ","  @ @  ","   @   ","  @ @  "," @   @ ","@     @"};
	letter['Y'] = {"@     @"," @   @ ","  @ @  ","   @   ","   @   ","   @   ","   @   "};
	letter['Z'] = {"@@@@@@@","     @ ","    @  ","   @   ","  @    "," @     ","@@@@@@@"};

}


// ============================================================================

void magnifier :: process(){
	
	// to get the word
	this->input();

	// to get the word's length
	length = word.size();

	// to regulate the total string
	this->regulate();

	// to present
	this->present();
}


// ============================================================================

void magnifier :: input(){ 
	
	// to get the word
	std::cout << "Enter the Word: ";
	std::getline(std::cin, word);

	//to get the alternative character
	std::cout << "Enter the character: ";
	std::cin >> element;
}


// ============================================================================

void magnifier :: regulate(){

	// to spin on the word's letters
	for (unsigned short C = 0; C < length; C++){
		for (unsigned short D = 0; D < LEN; D++){
			
			std::string dummyStr = letter[(char)toupper(word[C])][D] + " ";
			std::replace(dummyStr.begin(), dummyStr.end(), '@', element);
			bigWord[D] += (dummyStr); 
		}
	}
}

// ============================================================================

void magnifier :: present(){

	this->clrscr();
	for(unsigned short D = 0; D < LEN; D++)
		std::cout << bigWord[D] << '\n';
	
}

#endif // MAGNIFIER_H
