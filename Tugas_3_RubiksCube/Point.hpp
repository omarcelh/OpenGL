#ifndef POINT_H
#define POINT_H

#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <cmath>

using namespace std;

#define X_PLUS	Point(1,0,0)
#define Y_PLUS	Point(0,1,0)
#define Z_PLUS	Point(0,0,1)

class Point{
	public:
		//core
		Point();
		Point(const GLfloat x, const GLfloat y, const GLfloat z);
		friend ostream& operator<<(ostream &out, const Point &P);
		//methods
		GLfloat getX();
		GLfloat getY();
		GLfloat getZ();
		void setX(const GLfloat x);
		void setY(const GLfloat y);
		void setZ(const GLfloat z);
		Point operator/(GLfloat divisor);
		Point operator+(Point P);
		Point operator-(Point P);
		Point operator*(Point P);
		void rotate(Point origin, float degree, Point axis);
		void rotate(Point origin, float alpha, float beta, float gamma);
		
	private:
		//attributes
		GLfloat x;
		GLfloat y;
		GLfloat z;
};

#endif


