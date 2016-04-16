#include "Rubiks.hpp"

Rubiks::Rubiks() : defaultPosition(Point(0,0,0)), defaultSize(0.2) {
	position = defaultPosition;
	size = defaultSize;
	
	Color *colors = new Color[6];
	colors[0] = Color(0.5, 0.5, 0.5);
	colors[1] = Color(1,1,0);
	colors[2] = GREEN;
	colors[3] = BLUE;
	colors[4] = RED;
	colors[5] = Color(1,0.5,0);

	Point p(position.getX() - size, position.getY() - size, position.getZ() - size); // kiri bawah depan
	Point base(position.getX() - size, position.getY() - size, position.getZ() - size);

	for(int i=0; i<RUBIX_COUNT; i++) {
		p.setY(base.getY());
		for(int j=0; j<RUBIX_COUNT; j++) {
			p.setX(base.getX());
			for(int k=0; k<RUBIX_COUNT; k++) {
				cubes[i][j][k] = Cube(p,size,colors);
				p.setX(p.getX() + size);
			}
			p.setY(p.getY() + size);
		}
		p.setZ(p.getZ() + size);
	}

}

Rubiks::Rubiks(Point p, GLfloat size) : defaultPosition(Point(0,0,0)), defaultSize(0.2) {

}

Rubiks::Rubiks(const Rubiks &r) : defaultPosition(Point(0,0,0)), defaultSize(0.2) {

}

Rubiks& Rubiks::operator=(const Rubiks &r) {

}

Rubiks::~Rubiks() {

}

ostream& operator<<(ostream &out, const Rubiks &rubiks) {

}

Point Rubiks::getPosition() {
	return position;
}

GLfloat Rubiks::getSize() {
	return size;
}

void Rubiks::draw() {
	for(int i=0; i<RUBIX_COUNT; i++) {
		for(int j=0; j<RUBIX_COUNT; j++) {
			for(int k=0; k<RUBIX_COUNT; k++) {
				cubes[i][j][k].draw();
				cubes[i][j][k].drawBlackOutline();
			}
		}
	}
}