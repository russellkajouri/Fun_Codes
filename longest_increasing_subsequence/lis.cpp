/* ******************************************************************
 * This is a simple code to calculate the longest increasing subseq.
 *
 * Author :: kajothecoder@gmail.com
 * last modified :: 4 Aug 2021
 *
 *
 * *****************************************************************/

// ******************************************************************

#include <vector>
#include <iostream>
#include <set>

// ******************************************************************

constexpr unsigned short ZERO = 0;
constexpr unsigned short ONE  = 1;

// ******************************************************************

template <typename T>
void print_vec(std::vector<std::vector<T>> &vec){
	for(auto d: vec){
		for(auto dd: d)
			std::cout<< dd <<" ";
		std::cout<<std::endl;
	}
}

template <typename T>
void calc_LIS(std::vector <T> &D){
	std::vector<std::vector<T>> L(D.size());

	L[ZERO].push_back(D[ZERO]);

	for(unsigned int i=ONE; i<D.size(); i++) {
		for(unsigned int j=ZERO; j<i; j++)
			if( (D[j]<D[i]) && (L[i].size() < L[j].size()+ONE) )
				L[i] = L[j];
		L[i].push_back(D[i]);
	}//end of the loop with i iterator

	std::cout<<L[L.size()-ONE].size()<<std::endl;
	print_vec(L);
}

// ******************************************************************

int main() {

	int a[] {3, 2, 6, 7, 5, 1};
	std::vector <int> arr(a, a + sizeof(a)/sizeof(a[ZERO]));
	calc_LIS(arr);

	return ZERO;
}
// ******************************************************************
