#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::vector<std::string> split(const std::string& s, char delimiter){

   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {   
      tokens.push_back(token);
   }   
   return tokens;
}



string FindIntersection(string strArr[], int arrLength) {

  std::vector<std::string> elems01, elems02;
  std::vector<int> elems01int, elems02int;

  elems01 = split(strArr[0], ',');
  elems02 = split(strArr[1], ',');
  
  elems01int.resize(elems01.size(), 0);
  elems02int.resize(elems02.size(), 0);

  for(long unsigned int I=0; I<elems01.size(); I++)
    elems01int[I] = std::stoi(elems01[I]);
  for(long unsigned int I=0; I<elems02.size(); I++)
    elems02int[I] = std::stoi(elems02[I]);
  
  //elems01.erase(elems01.begin(), elems01.end());
  //elems02.erase(elems02.begin(), elems02.end());

  string str = "";
  for(long unsigned int I=0; I < elems01int.size(); I++)
    for(long unsigned int J=0; J < elems02int.size(); J++)
      if(elems01int[I] == elems02int[J])
        str += std::to_string(elems01int[I]) + ",";
  
    str.pop_back();

  // code goes here  
  return str;

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
    
}
