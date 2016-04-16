#include "cube3d.hpp"
#include <cassert>
 
cube3d::cube3d(){
  xpos = 0;
  ypos = 0;
  zpos = 0;
}

cube3d::cube3d(GLfloat x, GLfloat y, GLfloat z, GLfloat sisi_cube){
  xpos = x;
  ypos = y;
  zpos = z;
  sisi = sisi_cube;
}
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void cube3d::draw(){
  
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  //glTranslatef(-1,-1,-1);
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  //glTranslatef(1.5,1.5,1.5);
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );
 
  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included
 
  //Yellow side - FRONT
  glBegin(GL_POLYGON);
 
  glColor3f( 1.0, 1.0, 0.0 );     glVertex3f(  xpos+(sisi/2), ypos-(sisi/2), zpos-(sisi/2) );//kanan bwh      
    glVertex3f(  xpos+(sisi/2),  ypos+(sisi/2), zpos-(sisi/2) );//kanan atas      
    glVertex3f( xpos-(sisi/2),  ypos+(sisi/2), zpos-(sisi/2) );//kiri atas      
    glVertex3f( xpos-(sisi/2), ypos-(sisi/2), zpos-(sisi/2) );//kiri bawah      
 
  glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(xpos+(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f(xpos+(sisi/2), ypos-(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos+(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f(xpos-(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos+(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos-(sisi/2), zpos-(sisi/2));
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(xpos+(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos+(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos+(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos+(sisi/2), zpos+(sisi/2));
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(xpos+(sisi/2), ypos-(sisi/2), zpos-(sisi/2));
  glVertex3f(xpos+(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos-(sisi/2), zpos+(sisi/2));
  glVertex3f(xpos-(sisi/2), ypos-(sisi/2), zpos-(sisi/2));
  glEnd();
 
  glFlush();
  glutSwapBuffers();
 
}
double cube3d::getRotatex(){return rotate_x;};
double cube3d::getRotatey(){return rotate_y;};
double cube3d::getRotatez(){return rotate_z;};
GLfloat cube3d::getXpos(){return xpos;};
GLfloat cube3d::getYpos(){return ypos;};
GLfloat cube3d::getZpos(){return zpos;};
GLfloat cube3d::getsisi(){return sisi;};
void cube3d::rotateX(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut)
{

  rotate_x = sudut;
  

}

void cube3d::rotateY(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut)
{
  rotate_y = sudut;
  //glTranslatef (pusatx, pusaty, pusatz);
  //glutPostRedisplay();
}

void cube3d::rotateZ(GLfloat pusatx, GLfloat pusaty, GLfloat pusatz, double sudut)
{
  rotate_z = sudut;
  //glTranslatef (pusatx, pusaty, pusatz);
  //glutPostRedisplay();
}
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
  float a,pusatx,pusaty,pusatz; 
 int pilihan;
  cout << "masukan panjang sisi, pusat x, pusat y, pusat z (range -1 s/d 1)" << endl ;  
  cin >> a;
  cin >> pusatx;
  cin >> pusaty;
  cin >> pusatz;

  cout << "pilihan 1. rotate sb-x , 2. rotate sb-y, 3. rotate sb-z" <<endl;
  cin >> pilihan;
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutInitWindowSize(500,500);
  glutCreateWindow("Chinese Cube");
  
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  cube3d cube(pusatx,pusaty,pusatz,a);
  cube.draw();
  //rotate sb x 180
  if(pilihan == 1){
  cube.rotateX(0,0,0,90);
  }
  if(pilihan == 2){
  cube.rotateY(0,0,0,90); 
}
  if(pilihan == 3){
  cube.rotateZ(0,0,0,90);

}
  cube.draw();
  

 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}