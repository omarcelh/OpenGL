#include "Square.hpp"
#include <cassert>

const int Square::CORNER = 4;

Square::Square(){
	for(int i=0; i<CORNER; i++){
		points[i] = Point(0.0f, 0.0f, 0.0f);
	}
	color = WHITE;
}

Square::Square(Point points[4], Color color){
	for(int i=0; i<CORNER; i++){
		this->points[i] = points[i];
	}
	
	this->color = color;
}

Square::Square(Point p1, Point p2, Point p3, Point p4, Color color){
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	
	this->color = color;
}

ostream& operator<<(ostream &out, const Square &P){
	for(int i=0; i<Square::CORNER; i++){
		out << P.points[i] << endl;
	}
	out << P.color << endl;
	
	return out;
}
		
Point Square::getPointAt(int index){
	assert(index>=0 && index<CORNER);
	return points[index];
}

void Square::setPointAt(int index, const Point P){
	assert(index>=0 && index<CORNER);
	points[index] = P;
}

Color Square::getColor(){
	return color;
}

void Square::setColor(Color color){
	this->color = color;
}

void Square::draw() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glColor3f(color.getRed(), color.getBlue(), color.getGreen());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
	glEnd();
}

void Square::drawOutline(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glColor3f(color.getRed(), color.getBlue(), color.getGreen());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
	glEnd();
}


