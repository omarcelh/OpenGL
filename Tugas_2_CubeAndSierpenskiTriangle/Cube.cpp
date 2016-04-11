#include "Cube.hpp"
#include <cassert>

const int Cube::SIDE = 6;

Cube::Cube(){
	for(int i=0; i<SIDE; i++){
		squares = Square();
	}
	color = WHITE;
}

Cube::Cube(Point points[4], Color color){
	for(int i=0; i<SIDE; i++){
		this->squares[i] = squares[i];
	}
	
	this->color = color;
}

Cube::Cube(Point p1, Point p2, Point p3, Point p4, Color color){
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	
	this->color = color;
}

ostream& operator<<(ostream &out, const Cube &P){
	for(int i=0; i<Cube::SIDE; i++){
		out << P.points[i] << endl;
	}
	out << P.color << endl;
	
	return out;
}
		
Point Cube::getPointAt(int index){
	assert(index>=0 && index<SIDE);
	return points[index];
}

void Cube::setPointAt(int index, const Point P){
	assert(index>=0 && index<SIDE);
	points[index] = P;
}

Color Cube::getColor(){
	return color;
}

void Cube::setColor(Color color){
	this->color = color;
}

void Cube::draw() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glColor3f(color.getRed(), color.getBlue(), color.getGreen());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
	glEnd();
}

void Cube::drawOutline(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glColor3f(color.getRed(), color.getBlue(), color.getGreen());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
	glEnd();
}



