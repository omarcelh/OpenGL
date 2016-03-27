#include "GL/freeglut.h"
#include "GL/gl.h"
void Triangle()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glShadeModel(GL_SMOOTH);
 	glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1);
        glVertex3f(-0.3, 0, 0);
	glColor3f(1, 1, 1);
        glVertex3f(0, 0.5, 0);
	glColor3f(0, 0, 1);
        glVertex3f(0.3, 0, 0);
        glEnd();
//2nd Triangle
	glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 1);
        glVertex3f(-0.3, 0, 0);
	glColor3f(1, 1, 0);
        glVertex3f(0, -0.5, 0);
	glColor3f(0, 1, 1);
        glVertex3f(0.3, 0, 0);
        glEnd();
//3rd Triangle
	glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);
        glVertex3f(-0.6, -0.5, 0);
	glColor3f(1, 0, 0);
        glVertex3f(-0.3, 0, 0);
	glColor3f(0.5, 0, 0);
        glVertex3f(0, -0.5, 0);
        glEnd();
//4th Triangle
	glBegin(GL_TRIANGLES);
        glColor3f(0, 1, 0);
        glVertex3f(0, -0.5, 0);
	glColor3f(0, 0.5, 0);
        glVertex3f(0.3, 0, 0);
	glColor3f(1, 1, 1);
        glVertex3f(0.6, -0.5, 0);
        glEnd();
	glFlush();
}
/* Main method - main entry point of application
the freeglut library does the window creation work for us, 
regardless of the platform. */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - Tugas 1");
    glutDisplayFunc(Triangle);
    glutMainLoop();    
    return 0;
}
