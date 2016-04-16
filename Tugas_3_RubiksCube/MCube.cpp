#include "Cube.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

void display();
void reshape(int width, int height);
void specialKeys(int key, int x, int y);

// Global variable
Cube C1, C2;
double rotate_x=0, rotate_y=0, rotate_z=0;

const double ROTATION = 5;

int main(int argc, char** argv){
	/* Initialize */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - Tugas 3");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);

	/* Initialize for drawing */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); \
	glLoadIdentity();

	// Draw here
	Point center1 = Point(-0.3,-0.3,0);
	Point center2 = Point(0.3,0.3,0);
	float side1 = 0.45;
	float side2 = 0.55;
	Color *colors = new Color[6];
	colors[0] = Color(0.5, 0.5, 0.5);
	colors[1] = Color(1,1,0);
	colors[2] = GREEN;
	colors[3] = BLUE;
	colors[4] = RED;
	colors[5] = Color(1,0.5,0);
	
	C1 = Cube(center1, side1, colors);
	C2 = C1;
	C2.move(side1, side1, side1);

	/* Finalize */
	glutSwapBuffers();
	glutMainLoop();

	return 0;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glRotatef( rotate_z, 0.0, 0.0, 1.0 );

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	
	C1.draw();
	C2.drawOutline();
	
	usleep(50000);
	
	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height){
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(0.0f, aspectRatio*2, 0.1f, 100.0f);
}

void specialKeys( int key, int x, int y ) {
	switch(key){
		case GLUT_KEY_RIGHT	: rotate_y += ROTATION; break;
		case GLUT_KEY_LEFT	: rotate_y -= ROTATION; break;
		case GLUT_KEY_UP	: rotate_x += ROTATION; break;
		case GLUT_KEY_DOWN	: rotate_x -= ROTATION; break;
		case GLUT_KEY_F1	: rotate_z += ROTATION; break;
		case GLUT_KEY_F2	: rotate_z -= ROTATION; break;
		default: break;
	}
	
	glutPostRedisplay();

}

