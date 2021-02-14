/* ******************************************************************
 * last modified 14 Feb 2021
 * @author Kajo
 * @email rasoulkajouri@gmail.com
 *
 * *****************************************************************/
// ******************************************************************
// essential libraries
#include <iostream>
#include <string>
#include <stdio.h>

// ******************************************************************
bool IsPalindroma(const std::string&);

// ******************************************************************
int main(int argc, char *argv[]){

	std::string text;
	if (argc>1)
		text = argv[1];
	else{
		std::printf("Enter your sentence: ");
		std::getline(std::cin, text);
	}

	if(IsPalindroma(text))
		std::printf("\'%s\' is Palindroma!\n", text.c_str());
	else
		std::printf("\'%s\' is NOT Palindroma!\n", text.c_str());

	return EXIT_SUCCESS;
}

// ******************************************************************
bool IsPalindroma(const std::string &txt){

	unsigned int l = 0, h = txt.length()-1;
	while(h>l)
		if(txt[l++] != txt[h--])
			return false;
	return true;
}
