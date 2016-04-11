#include "Point.hpp" 

Point::Point(){
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point::Point(const GLfloat x, const GLfloat y, const GLfloat z){
	this->x = x;
	this->y = y;
	this->z = z;
}
		
ostream& operator<<(ostream &out, const Point &P){
	out << "(" << P.x << ", "<< P.y << ", " << P.z << ")";
	return out;
}

//methods
GLfloat Point::getX(){
	return x;
}

GLfloat Point::getY(){
	return y;
}

GLfloat Point::getZ(){
	return z;
}

void Point::setX(const GLfloat x){
	this->x = x;
}

void Point::setY(const GLfloat y){
	this->y = y;
}

void Point::setZ(const GLfloat z){
	this->z = z;
}

Point Point::operator/(GLfloat divisor){
	Point temp = Point(*this);
	temp.x /= divisor;
	temp.y /= divisor;
	temp.z /= divisor;
	return temp;
}

Point Point::operator+(Point P){
	Point temp = Point(*this);
	temp.x += P.x;
	temp.y += P.y;
	temp.z += P.z;
	return temp;
}

