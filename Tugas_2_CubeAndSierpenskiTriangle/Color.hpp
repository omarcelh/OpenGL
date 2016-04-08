#ifndef COLOR_H
#define COLOR_H

#include "GL/freeglut.h"
#include "GL/gl.h"

#define RED 	Color(1, 0, 0)
#define GREEN 	Color(0, 1, 0)
#define BLUE 	Color(0, 0, 1)
#define WHITE 	Color(0, 0, 0)
#define BLACK	Color(1, 1, 1)

#include <iostream>
using namespace std;

class Color {
	public:
		Color();
		Color(GLfloat r, GLfloat g, GLfloat b);
		GLfloat getRed();
		GLfloat getGreen();
		GLfloat getBlue();
		void setColor(GLfloat r, GLfloat g, GLfloat b);
		void getAllColor(GLfloat& r, GLfloat& g, GLfloat& b);
		friend ostream& operator<< (ostream& stream, const Color& color);
	private:
		GLfloat red;
		GLfloat green;
		GLfloat blue;
};

#endif


