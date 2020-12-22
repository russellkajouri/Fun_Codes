/************************************************
 * 
 * Project: COLORFULL TEXTS
 * Last modified : 21 Dec. 2020 11:09 A.M.
 *
 *
 * Copy Left, all lefts reserved!
 *
 ************************************************/


#include <vector>
#include <iostream>
#include "colors.hpp"

int main(){

	colors palette;

	// colorSet(mode, color, opacity)
	// mode -> bold, dim, underlined, blink, inverted, hidden
	// mode -> b, d, u, b, i, h [short form]
	//
	// color -> black, red, green, yellow, blue, magenta, cyan, gray, white
	// color -> b, r, g, y, bl, mag, c, gr, w, [short form]
	//
	// opacity -> dark, light
	// opacity -> d, l

	// ----------------------------------------------------
	// to have a bold dark red text
	
	std::cout << palette.colorSet("bold", "red", "dark") << "a bold dark red text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';

	std::cout << palette.colorSet("b", "r", "d") << "a bold dark red text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';

		
	std::cout << palette.colorSet({"bold","blink"}, "green", "dark") << "a bold blink dark green text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';
	
	std::cout << palette.colorSet({"bold","bold"}, "y", "l") << "a underlined dim yellow text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';

	std::cout << palette.colorSet("bold", "red", "light") << "a bold dark red text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';

	std::cout << palette.colorSet("", "r", "l") << "a bold dark red text" << '\n';
	std::cout << palette.colorSet() << "a normal text" << '\n';

	//std::cout << palette.colorSet() << "a normal text" << '\n';


	return 0;
}
