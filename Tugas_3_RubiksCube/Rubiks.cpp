#include "Rubiks.hpp"

Rubiks::Rubiks() : defaultPosition(Point(0,0,0)), defaultSize(100) {
	position = defaultPosition;
	size = defaultSize;
	Point p(position.x - size, position.y - size, position.z - size); // kiri bawah depan
	for(int i=0; i<cubes.size(); i++) {
		for(int j=0; j<cubes[i].size(); j++) {
			for(int k=0; k<cubes[i][j].size; k++) {
				cubes = Cube();
			}
		}
	}
}

Rubiks::Rubiks(Point p, GLfloat size) : defaultPosition(Point(0,0,0)), defaultSize(100) {

}

Rubiks::Rubiks(const Rubiks &r) : defaultPosition(Point(0,0,0)), defaultSize(100) {

}

Rubiks& Rubiks::operator=(const Rubiks &r) {

}

Rubiks::~Rubiks() {

}

ostream& operator<<(ostream &out, const Rubiks &rubiks) {

}

Point Rubiks::getPosition() {
	return postion;
}

GLfloat Rubiks::getSize() {
	return size;
}