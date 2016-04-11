#include "Square.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
	Square T;
	cout << T << endl;
	
	Point *P = new Point[4];
	P[0] = Point(-1, -1, 0);
	P[1] = Point(-1, 1, 0);
	P[2] = Point(1, 1, 0);
	P[3] = Point(1, -1, 0);
	Square *T1 = new Square(P, RED);
	cout << *T1 << endl;
	
	Square T2(P[0], P[1], P[2], P[3], BLUE);
	Square T3 = T2;
	
	T3.setPointAt(0, Point(-0.4, 0, 0));
	
	cout << T2 << endl;
	cout << T3 << endl;
	
	return 0;
}
