#include "GL/freeglut.h"
#include "GL/gl.h"
#include "Triangle.hpp"

Point dividePoint(Point e1, Point e2) {
    GLfloat x = (e2.getX() + e1.getX())/2;
    GLfloat y = (e2.getY() + e1.getY())/2;
    GLfloat z = e2.getZ();
    Point result(x,y,z);
    return result;
}

void drawSerpenskiTriangle(Point &edge1, Point &edge2, Point &edge3, Color &inner, Color &outer, int n) {
    if(n <= 0 ) {
        // Stop
    } else {
        Point p1 = dividePoint(edge1, edge2);
        Point p2 = dividePoint(edge2, edge3);
        Point p3 = dividePoint(edge3, edge1);
        Triangle triangle(edge1,edge2,edge3,outer);
        triangle.draw();
        triangle.setTriangle(p1,p2,p3,inner);
        triangle.draw();
        n--;
        drawSerpenskiTriangle(edge1,p1,p3,inner,outer,n);
        drawSerpenskiTriangle(p1,edge2,p2,inner,outer,n);
        drawSerpenskiTriangle(p3,p2,edge3,inner,outer,n);
    }
}

int main(int argc, char** argv) {
    /* Initialize */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - Tugas 2");
    
    /* Initialize for drawing */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); \
    glLoadIdentity(); 

    /* Initialize Serpenski Triangle Size */
    Point edge1(-1.0f, -1.0f, 1.0f);
    Point edge2(0, 1.0f, 1.0f);
    Point edge3(1.0f, -1.0f, 1);
    Color color(1,1,1);
    Triangle triangle(edge1,edge2,edge3,color);
    triangle.draw();
    Color outer(1,1,1);
    Color inner(0,0,0);
    drawSerpenskiTriangle(edge1,edge2,edge3,inner,outer,5);
    
    /* Finalize */
    glutSwapBuffers();
    glutMainLoop();    
    return 0;
}
