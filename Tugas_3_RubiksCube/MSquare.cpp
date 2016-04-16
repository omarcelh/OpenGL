#include "Square.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

void display();
void reshape(int width, int height);

// Global variable
Square S1, S2;

int main(int argc, char** argv){
	/* Initialize */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - Tugas 2");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	/* Initialize for drawing */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); \
	glLoadIdentity();

	// Draw here
	Point *P = new Point[4];
	P[0] = Point(-1, -1, 0);
	P[1] = Point(-1, 0, 0);
	P[2] = Point(0, 0, 0);
	P[3] = Point(0, -1, 0);
	S1 = Square(P, WHITE);
	
	P[0] = Point(0, 0, 0);
	P[1] = Point(0, 1, 0);
	P[2] = Point(1, 1, 0);
	P[3] = Point(1, 0, 0);
	S2 = Square(P, GREEN);
	
	/* Finalize */
	glutSwapBuffers();
	glutMainLoop();

	return 0;
}


void display(){
	for(int i=0; i<30; i++){
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 1.0, 1.0);
		glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
		glShadeModel(GL_SMOOTH);
		
		S1.rotate(S1.getCenterPoint(), i*2, i*2, i*2);
		S2.rotate(S2.getCenterPoint(), -i*2, -i*2, -i*2);
		S1.draw();
		S2.drawOutline();
		usleep(100000);
		
		glFlush();
	}
}

void reshape(int width, int height){
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(0.0f, aspectRatio*2, 0.1f, 100.0f);
}
