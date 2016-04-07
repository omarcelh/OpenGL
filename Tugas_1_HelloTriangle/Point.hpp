#ifndef POINT_H
#define POINT_H

#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>

using namespace std;

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
		
	private:
		//attributes
		GLfloat x;
		GLfloat y;
		GLfloat z;
};

#endif


