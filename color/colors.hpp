#ifndef COLORS_HPP
#define COLORS_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <initializer_list>

class colors {
	private:

		std::string text = "";
		short color_counter;
		enum color {
			black = 1, 
			red, 
			green,
			yellow,
			blue,
			magenta,
			cyan,
			gray,
			white
		};

		std::map <std::string, color> map_color{
			
			{"black"  , black  },
			{"red"    , red    },
			{"green"  , green  },
			{"yellow" , yellow },
			{"blue"   , blue   },
			{"magenta", magenta},
			{"cyan"   , cyan   },
			{"gray"   , gray   },
			{"white"  , white  },
	
			{"b"   , black  },
			{"r"   , red    },
			{"g"   , green  },
			{"y"   , yellow },
			{"bl"  , blue   },
			{"mag" , magenta},
			{"c"   , cyan   },
			{"gr"  , gray   },
			{"w"   , white  },
		};

		enum mode {
			bold = 1,
			dim,
			underlined,
			blink,
			inverted,
			hidden
		};

		std::map <std::string, mode> map_mode{
			
			{"bold"       , bold       },
			{"dim"        , dim        },
			{"underlined" , underlined },
			{"blink"      , blink      },
			{"inverted"   , inverted   },
			{"hidden"     , hidden     },

			{"b"  , bold       },
			{"d"  , dim        },
			{"u"  , underlined },
			{"bl" , blink      },
			{"i"  , inverted   },
			{"h"  , hidden     }
		};

		enum opacity{
			dark = 1,
			light
		};

		std::map <std::string, opacity> map_opacity{
			
			{"dark" , dark },
			{"light", light},

			{"d", dark },
			{"l", light}
		
		};

	public:
		std::string colorSet();
		std::string colorSet(std::initializer_list <std::string>, std::string, std::string);
		std::string colorSet(std::string, std::string, std::string);


};


// to set default 
std::string colors :: colorSet(){
	return "\e[0m";
}

// --------------------------------------------------------
std::string colors :: colorSet(std::initializer_list<std::string> md, std::string cl, std::string op){


	opacity opc = map_opacity [op];
	color   clr = map_color   [cl];

	text = "\e[";

	// to find the opcaity of the color
	switch(opc) {
		case dark:
			color_counter = 90;
			break;
		case light:
			color_counter = 30;
			break;
		default:
			color_counter = 0;
	}

	for (std::string x : md){
	
		mode mod = map_mode [x];

		// to set mode of the text
		switch (mod){
		
			case bold:
				text += "1";
				break;
			case dim:
				text += "2";
				break;
			case underlined:
				text += "4";
				break;
			case blink:
				text += "5";
				break;
			case inverted:
				text += "7";
				break;
			case hidden:
				text += "8";
				break;
			default:
				text += "0";
		
		}

		text += ";";
	
	}


	// to set color of the text
	switch(clr){
		
		case black:
			color_counter = 30;
			break;
		case red:
			color_counter += 1;
			break;
		case green:
			color_counter +=2;
			break;
		case yellow:
			color_counter +=3;
			break;
		case blue:
			color_counter +=4;
			break;
		case magenta:
			color_counter +=5;
			break;
		case cyan:
			color_counter +=6;
			break;
		case gray:
			color_counter = opc == dark ? 90 : 37;
			break;
		case white:
			color_counter = 97;
		default:
			color_counter = 0;
	}

	text += std::to_string(color_counter) + "m";



	return text;

}


// --------------------------------------------------------

// to set oen option for each argument
std::string colors :: colorSet(std::string md, 
		std::string cl, std::string op){

	opacity opc = map_opacity [op];
	color   clr = map_color   [cl];
	mode    mod = map_mode    [md];

	text = "\e[";


	// to find the opcaity of the color
	switch(opc) {
		case dark:
			color_counter = 90;
			break;
		case light:
			color_counter = 30;
			break;
		default:
			color_counter = 0;
	}

	//std::cout << color_counter << '\n';


	// to set mode of the text
	switch (mod){
	
		case bold:
			text += "1";
			break;
		case dim:
			text += "2";
			break;
		case underlined:
			text += "4";
			break;
		case blink:
			text += "5";
			break;
		case inverted:
			text += "7";
			break;
		case hidden:
			text += "8";
			break;
		default:
			text += "0";
	
	}

	text += ";";

	// to set color of the text
	switch(clr){
		
		case black:
			color_counter = 30;
			break;
		case red:
			color_counter += 1;
			break;
		case green:
			color_counter +=2;
			break;
		case yellow:
			color_counter +=3;
			break;
		case blue:
			color_counter +=4;
			break;
		case magenta:
			color_counter +=5;
			break;
		case cyan:
			color_counter +=6;
			break;
		case gray:
			color_counter = opc == dark ? 90 : 37;
			break;
		case white:
			color_counter = 97;
		default:
			color_counter = 0;
	}

	text += std::to_string(color_counter) + "m";

	return text;
}

#endif // COLORS
