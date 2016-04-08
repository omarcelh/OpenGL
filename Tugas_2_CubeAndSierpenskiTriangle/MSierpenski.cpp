#include "GL/freeglut.h"
#include "GL/gl.h"
#include "Triangle.hpp"

void display();
void reshape(int width, int height);

int main(int argc, char** argv) {
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
    
    /* Finalize */
    glutSwapBuffers();
    glutMainLoop();    
    return 0;
}

void display(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glShadeModel(GL_SMOOTH);
 	
 	/* Initialize Serpenski Triangle Size */
	Point edge1(-1.0f, -1.0f, 0.0f); //Bottom left
	Point edge2(0, 1.0f, 0.0f); //Upper
	Point edge3(1.0f, -1.0f, 0.0f); //Bottom Right
	
	Triangle triangle(edge1,edge2,edge3,WHITE);
	Color *color = new Color[6];
	color[0] = RED;
	color[1] = GREEN;
	color[2] = BLUE;
	color[3] = WHITE;
	color[4] = BLACK;
	color[5] = Color(0.5, 0.5, 0.5);
	
	triangle.drawSierpinski(color, 6, Triangle::SIERPINSKI_OUTLINE);
	
	glFlush();
}

void reshape(int width, int height){
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluPerspective(0.0f, aspectRatio*2, 0.1f, 100.0f);
}

