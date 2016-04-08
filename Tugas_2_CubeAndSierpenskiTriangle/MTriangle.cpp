#include "Triangle.hpp"

int numTriangles = 4;
Triangle* triangles = new Triangle[numTriangles];

void draw(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glShadeModel(GL_SMOOTH);
 	
 	for(int i=0; i<numTriangles; i++){
		if(i==1){
			//gradient - hardcode
			glBegin(GL_TRIANGLES);
		
			//1st point
			glColor3f(1, 0, 0); //red
			glVertex3f(triangles[i].getPointAt(0).getX(), triangles[i].getPointAt(0).getY(), triangles[i].getPointAt(0).getZ());
			//2nd point
			glColor3f(0, 1, 0); //green
			glVertex3f(triangles[i].getPointAt(1).getX(), triangles[i].getPointAt(1).getY(), triangles[i].getPointAt(1).getZ());
			//3rd point
			glColor3f(0, 0, 1); //blue
			glVertex3f(triangles[i].getPointAt(2).getX(), triangles[i].getPointAt(2).getY(), triangles[i].getPointAt(2).getZ());
			
			glEnd();
		} else {
			glBegin(GL_TRIANGLES);
			
			int r=triangles[i].getColor().getRed(), g=triangles[i].getColor().getGreen(), b=triangles[i].getColor().getBlue();
			
			//1st point
			glColor3f(r, g, b);
			glVertex3f(triangles[i].getPointAt(0).getX(), triangles[i].getPointAt(0).getY(), triangles[i].getPointAt(0).getZ());
			//2nd point
			glColor3f(r, g, b);
			glVertex3f(triangles[i].getPointAt(1).getX(), triangles[i].getPointAt(1).getY(), triangles[i].getPointAt(1).getZ());
			//3rd point
			glColor3f(r, g, b);
			glVertex3f(triangles[i].getPointAt(2).getX(), triangles[i].getPointAt(2).getY(), triangles[i].getPointAt(2).getZ());
			
			glEnd();
		}
	}
	
	glFlush();
}

int main(int argc, char** argv){
	triangles[0] = Triangle(Point(-0.3, 0, 0), Point(0, 0.5, 0), Point(0.3, 0, 0), RED);
	triangles[1] = Triangle(Point(-0.3, 0, 0), Point(0, -0.5, 0), Point(0.3, 0, 0), RED); //hardcode gradasi
	triangles[2] = Triangle(Point(-0.6, -0.5, 0), Point(-0.3, 0, 0), Point(0, -0.5, 0), GREEN);
	triangles[3] = Triangle(Point(0, -0.5, 0), Point(0.3, 0, 0), Point(0.6, -0.5, 0), BLUE);
	
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300, 80);
    glutCreateWindow("OpenGL - Tugas 1");
    glutDisplayFunc(draw);
    glutMainLoop();    
	return 0;
}

