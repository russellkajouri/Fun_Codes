#include <iostream>
using namespace std;


template <typename T, typename G>
class compute{
	private:
		void swap(T&, T&);
	public:
		void reverse(T *&, G&);

};

template <typename T, typename G>
void compute<T,G> :: reverse(T *&arr, G &len){
    for(G l=0; l < (len/(G)2); l++)
        this->swap(arr[l], arr[len - l - 1]);
}

template <typename T, typename G>
void compute<T,G> :: swap(T &a, T &b){
    a += b;
    b = a - b;
    a -=b ;
}

int main() {
	//code
	//
	compute <unsigned int ,unsigned int> com ;
	unsigned int len, *arr;
	
    // to get the values and build the arr array
	std::cin >> len;
	arr = new unsigned int [len];
	
	// to fill the array
	for(unsigned int l=0; l<len; l++)
	    std::cin>>arr[l];	

	com.reverse(arr, len);
	
	for(unsigned int l=0; l<len; l++)
		std::cout << arr[l] << " ";

    std::cout<<std::endl;	
	return 0;
}
