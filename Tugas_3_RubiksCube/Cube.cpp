#include "Cube.hpp"
#include <cassert>

const int Cube::SIDE = 6;

Cube::Cube(){
	squares = new Square[SIDE];
	for(int i=0; i<SIDE; i++){
		squares[i] = Square();
	}
}

Cube::Cube(Square squares[6]){
	this->squares = new Square[SIDE];
	for(int i=0; i<SIDE; i++){
		this->squares[i] = squares[i];
	}
}

Cube::Cube(Point center, GLfloat side, Color colors[6]){
	squares = new Square[SIDE];
	Square S_front, S_back, S_right, S_left, S_top, S_bottom;
	Point front_bottomleft, front_topleft, front_topright, front_bottomright;
	Point back_bottomleft, back_topleft, back_topright, back_bottomright;
	
	front_bottomleft = (center - Point(side/2, side/2, side/2));
	front_topleft = (center - Point(side/2, -side/2, side/2));
	front_topright = (center - Point(-side/2, -side/2, side/2));
	front_bottomright = (center - Point(-side/2, side/2, side/2));
	
	back_bottomleft = (center - Point(side/2, side/2, -side/2));
	back_topleft = (center - Point(side/2, -side/2, -side/2));
	back_topright = (center - Point(-side/2, -side/2, -side/2));
	back_bottomright = (center - Point(-side/2, side/2, -side/2));
	
	// Front
	squares[0] = Square(front_bottomleft, front_topleft, front_topright, front_bottomright, colors[0]);
	
	// Back
	squares[1] = Square(back_bottomleft, back_topleft, back_topright, back_bottomright, colors[1]);
	
	// Right
	squares[2] = Square(front_bottomright, front_topright, back_topright, back_bottomright, colors[2]);
	
	// Left
	squares[3] = Square(front_bottomleft, front_topleft, back_topleft, back_bottomleft, colors[3]);
	
	// Top
	squares[4] = Square(back_topleft, back_topright, front_topright, front_topleft, colors[4]);
	
	// Bottom
	squares[5] = Square(back_bottomleft, front_bottomleft, front_bottomright, back_bottomright, colors[5]);
	
	cout << *this << endl;
}

Cube::Cube(const Cube &C){
	squares = new Square[SIDE];
	for(int i=0; i<SIDE; i++){
		squares[i] = C.squares[i];
	}
}

Cube::~Cube(){
	delete[] squares;
}

Cube& Cube::operator=(const Cube &C){
	delete[] squares;
	this->squares = new Square[SIDE];
	for(int i=0; i<SIDE; i++){
		this->squares[i] = C.squares[i];
	}
	return *this;
}

ostream& operator<<(ostream &out, const Cube &P){
	for(int i=0; i<Cube::SIDE; i++){
		out << "Square-" << i << endl;
		out << P.squares[i] << endl;
	}
	
	return out;
}

Point Cube::getCenterPoint(){
	Point center;
	for(int i=0; i<SIDE; i++){
		for(int j=0; j<Square::CORNER; j++){
			center = center + squares[i].getPointAt(j);
		}
	}
	center = center / (SIDE * Square::CORNER);
	return center;
}

Square Cube::getSquareAt(int index){
	assert(index>=0 && index<SIDE);
	return squares[index];
}

void Cube::setSquareAt(int index, const Square S){
	assert(index>=0 && index<SIDE);
	squares[index] = S;
}

Color Cube::getColorAt(int index){
	assert(index>=0 && index<SIDE);
	return squares[index].getColor();
}

void Cube::setColorAt(int index, Color color){
	assert(index>=0 && index<SIDE);
	squares[index].setColor(color);
}

void Cube::draw() {
	for(int i=0; i<SIDE; i++){
		squares[i].draw();
	}
}

void Cube::drawOutline(){
	for(int i=0; i<SIDE; i++){
		squares[i].drawOutline();
	}
}

void Cube::rotate(Point origin, float alpha, float beta, float gamma){
	for(int i=0; i<SIDE; i++){
		squares[i].rotate(origin, alpha, beta, gamma);
	}
}

void Cube::move(float dx, float dy, float dz){
	for(int i=0; i<SIDE; i++){
		squares[i].move(dx, dy, dz);
	}
}

