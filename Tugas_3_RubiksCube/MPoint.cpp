#include <iostream>
#include "Point.hpp"
using namespace std;

int main(){
	Point P(5,5,5);
	cout << P+Point(5,5,5) << endl;
	cout << P << endl;
	cout << P/2.3 << endl;
	cout << P << endl;
	return 0;
}

