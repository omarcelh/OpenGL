#ifndef COLOR_H
#define COLOR_H

#define COLOR_H
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "Color.hpp"
#include <GL/glut.h>


#include <iostream>
using namespace std;

class cube3d {
	public:
		cube3d();
		//dengan titik pusat
		cube3d(GLfloat x, GLfloat y, GLfloat z, GLfloat sisi);
		void draw();
		double getRotatex();
		double getRotatey();
		double getRotatez();
		GLfloat getXpos();
		GLfloat getYpos();
		GLfloat getZpos();
		GLfloat getsisi();
		void rotateX(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut);
		void rotateY(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut);
		void rotateZ(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut);
	private:
		GLfloat xpos;
		GLfloat ypos;
		GLfloat zpos;
		double rotate_y=0; 
		double rotate_x=0;
		double rotate_z=0;
		GLfloat sisi=0;

};

#endif