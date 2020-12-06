#include <string>
#include <cctype>
#include <iostream>
#include <vector>
#include <cstdlib>

std::vector <char> word;
char charac, temp;
static unsigned int C = 0;

void clrscr() {system("@cls||clear");}

void catchText(){

	std::cout << "Write your word [terminate it by enter a number]: ";
    do{
        charac = getchar();
        if (isalpha(charac))
            word.push_back(charac);

    } while (!isdigit(charac));

    clrscr();
}

void typeText(){

    std::cout << "\033[2;32m you typed: \033[0m ";
    for (std::vector<char>::iterator it = word.begin(); it != word.end(); ++it)
        std::cout << *it;
    std::cout << "." << std::endl;
}

void print(){

    for (unsigned int a = 0; a < word.size(); a++)
        std::cout << word[a];
    
    if (C++ < 5){
        std::cout << "  ";
    }   
    else{
        std::cout << std::endl;
        C = 0;
    }

}
void process(){

    for(unsigned int c = 1; c <= word.size(); c++){

        for(unsigned int v = 0; v < word.size()-1; v++){

            temp = word[v];
            word[v] = word[v+1];
            word[v+1] = temp;
            print();
        }
    }

    std::cout << std::endl;
}


int main (){

    catchText();
    typeText();
    process();

    return 0;
}
