#include "Triangle.hpp"
#include <cassert>

const int Triangle::SIDE = 3;

Triangle::Triangle(){
	for(int i=0; i<3; i++){
		points[i] = Point(0.0f, 0.0f, 0.0f);
	}
	color = WHITE;
}

Triangle::Triangle(Point points[3], Color color){
	for(int i=0; i<3; i++){
		this->points[i] = points[i];
	}
	
	this->color = color;
}

Triangle::Triangle(Point p1, Point p2, Point p3, Color color){
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	
	this->color = color;
}

ostream& operator<<(ostream &out, const Triangle &P){
	for(int i=0; i<Triangle::SIDE; i++){
		out << P.points[i] << endl;
	}
	out << P.color << endl;
	
	return out;
}
		
Point Triangle::getPointAt(int index){
	assert(index>=0 && index<SIDE);
	return points[index];
}

void Triangle::setPointAt(int index, const Point P){
	assert(index>=0 && index<SIDE);
	points[index] = P;
}

Color Triangle::getColor(){
	return color;
}

void Triangle::setColor(Color color){
	this->color = color;
}

//int main(int argc, char** argv){
	//Triangle T;
	//cout << T << endl;
	
	//Point *P = new Point[3];
	//P[0] = Point(-0.3, 0, 0);
	//P[1] = Point(0, 0.5, 0);
	//P[2] = Point(0.3, 0, 0);
	
	//Triangle *T1 = new Triangle(P, RED);
	//cout << *T1 << endl;
	
	//Triangle T2(P[0], P[1], P[2], BLUE);
	//Triangle T3 = T2;
	
	//T3.setPointAt(0, Point(-0.4, 0, 0));
	
	//cout << T2 << endl;
	//cout << T3 << endl;
	
	//return 0;
//}

