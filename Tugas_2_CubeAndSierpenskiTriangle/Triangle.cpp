#include "Triangle.hpp"
#include <cassert>

const int Triangle::SIDE = 3;
const int Triangle::SIERPINSKI_FILL = -1;
const int Triangle::SIERPINSKI_OUTLINE = -2;

Triangle::Triangle(){
	for(int i=0; i<3; i++){
		points[i] = Point(0.0f, 0.0f, 0.0f);
	}
	color = WHITE;
}

Triangle::Triangle(Point points[3], Color color){
	for(int i=0; i<3; i++){
		this->points[i] = points[i];
	}
	
	this->color = color;
}

Triangle::Triangle(Point p1, Point p2, Point p3, Color color){
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	
	this->color = color;
}

ostream& operator<<(ostream &out, const Triangle &P){
	for(int i=0; i<Triangle::SIDE; i++){
		out << P.points[i] << endl;
	}
	out << P.color << endl;
	
	return out;
}
		
Point Triangle::getPointAt(int index){
	assert(index>=0 && index<SIDE);
	return points[index];
}

void Triangle::setPointAt(int index, const Point P){
	assert(index>=0 && index<SIDE);
	points[index] = P;
}

Color Triangle::getColor(){
	return color;
}

void Triangle::setColor(Color color){
	this->color = color;
}

void Triangle::draw() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glColor3f(color.getRed(), color.getBlue(), color.getGreen());
	glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
	glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
	glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
	glEnd();
}

void Triangle::drawOutline(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glColor3f(color.getRed(), color.getBlue(), color.getGreen());
	glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
	glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
	glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
	glEnd();
}

// colorMap size must have at least n elements
void Triangle::drawSierpinski(Color colorMap[], int n, int code){
	drawSierpinski(points[0], points[1], points[2], colorMap, n, code);
}

void Triangle::drawSierpinski(Point &edge1, Point &edge2, Point &edge3, Color colorMap[], int n, int code){
	if(n <= 0 ) {
		// Stop
	} else {
		Point p1 = (edge1 + edge2) / 2;
		Point p2 = (edge2 + edge3) / 2;
		Point p3 = (edge3 + edge1) / 2;
		Triangle inner_t(p1,p2,p3,colorMap[n-1]);

		switch(code){
			case SIERPINSKI_FILL:
				this->draw(); //outer triangle
				inner_t.draw(); //inner triangle
				break;
			case SIERPINSKI_OUTLINE:
				this->drawOutline(); //outer triangle
				inner_t.drawOutline(); //inner triangle
				break;
		}
		
		Triangle t1(edge1, p1, p3, colorMap[n-2]);
		Triangle t2(p1, edge2, p2, colorMap[n-2]);
		Triangle t3(p3, p2, edge3, colorMap[n-2]);
		
		t1.drawSierpinski(colorMap, n-1, code);
		t2.drawSierpinski(colorMap, n-1, code);
		t3.drawSierpinski(colorMap, n-1, code);
	}
}

//int main(int argc, char** argv){
	//Triangle T;
	//cout << T << endl;
	
	//Point *P = new Point[3];
	//P[0] = Point(-0.3, 0, 0);
	//P[1] = Point(0, 0.5, 0);
	//P[2] = Point(0.3, 0, 0);
	
	//Triangle *T1 = new Triangle(P, RED);
	//cout << *T1 << endl;
	
	//Triangle T2(P[0], P[1], P[2], BLUE);
	//Triangle T3 = T2;
	
	//T3.setPointAt(0, Point(-0.4, 0, 0));
	
	//cout << T2 << endl;
	//cout << T3 << endl;
	
	//return 0;
//}

