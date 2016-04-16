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

Point Point::operator-(Point P){
	Point temp = Point(*this);
	temp.x -= P.x;
	temp.y -= P.y;
	temp.z -= P.z;
	return temp;
}

Point Point::operator*(Point P){
	Point temp = Point(*this);
	temp.x *= P.x;
	temp.y *= P.y;
	temp.z *= P.z;
	return temp;
}

void Point::rotate(Point origin, float degree, Point axis){
	const float PI = 3.14159265;
	float sinDegree = sin(degree*(PI/180));
	float cosDegree = cos(degree*(PI/180));
	//float k = 1 - cosDegree;
	
	float temp_x = x;
	float temp_y = y;
	float temp_z = z;
	
	if(axis.x==1){
		//x remains the same
		temp_x = x;
		temp_y = y*cosDegree - z*sinDegree;
		temp_z = y*sinDegree + z*cosDegree;
	} else if (axis.y==1) {
		temp_x = x*cosDegree + z*sinDegree;
		temp_y = y;
		temp_z = z*cosDegree - x*sinDegree;
	} else if (axis.z==1) {
		temp_x = x*cosDegree - y*sinDegree;
		temp_y = x*sinDegree + y*cosDegree;
		temp_z = z;
	}
	
	x = temp_x;
	y = temp_y;
	z = temp_z;
}

void Point::rotate(Point origin, float alpha, float beta, float gamma){
	//moving rotation's reference to (0,0,0)
	x = (x - origin.x);
	y = (y - origin.y);
	z = (z - origin.z);
	
	rotate(origin, alpha, X_PLUS);
	rotate(origin, beta, Y_PLUS);
	rotate(origin, gamma, Z_PLUS);
	
	//moving rotation's reference back to first point
	x = (x + origin.x);
	y = (y + origin.y);
	z = (z + origin.z);
}

