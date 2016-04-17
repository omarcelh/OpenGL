#include "Rubiks.hpp"

Rubiks::Rubiks() : defaultPosition(Point(0,0,0)), defaultSize(0.2) {
	position = defaultPosition;
	size = defaultSize;
	currentAxis = 0; 
	currentLevel = 0;
	currentDegree = 0;
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

Rubiks::Rubiks(Point p, GLfloat size, Color* colors) : defaultPosition(Point(0,0,0)), defaultSize(0.2) {
	
}

Rubiks::Rubiks(const Rubiks &r) : defaultPosition(Point(0,0,0)), defaultSize(0.2) {

}

Rubiks& Rubiks::operator=(const Rubiks &r) {

}

Rubiks::~Rubiks() {
	// do nothing
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


/**
 * axis = 1, kalau diputarnya baris. axis = 2, kalau diputarnya kolom.
 * level, tingkatan dari rubiks dari 0, sampe 2.
 * degree, derajat putaran rubiks
 */
void Rubiks::rotateSide(int axis, int level, GLfloat degree) {
	if(currentAxis == 0) {
		currentAxis = axis;
		currentLevel = level;
		currentDegree = degree;
		if(axis == 1) { // Putar di bagian rownya.
			for(int i=0; i<RUBIX_COUNT; i++) {
				for(int j=0; j<RUBIX_COUNT; j++) {

					cubes[i][level][j].rotate(cubes[1][1][1].getCenterPoint(), 0, degree ,0);
				}
			}
		} else if(axis == 2) { // Putar di bagian kolom
			for(int i=0; i<RUBIX_COUNT; i++) {
				for(int j=0; j<RUBIX_COUNT; j++) {
					cubes[i][j][level].rotate(cubes[1][1][1].getCenterPoint(), degree, 0 ,0);
				}
			}
		} else if(axis == 3) {
			for(int i=0; i<RUBIX_COUNT; i++) {
				for(int j=0; j<RUBIX_COUNT; j++) {
					cubes[level][i][j].rotate(cubes[1][1][1].getCenterPoint(), 0, 0 ,degree);
				}
			}
		}
	} else {
		if(axis == currentAxis && level == currentLevel) { 
			if(axis == 1) { // Putar di bagian rownya.
				for(int i=0; i<RUBIX_COUNT; i++) {
					for(int j=0; j<RUBIX_COUNT; j++) {
						cubes[i][level][j].rotate(cubes[1][1][1].getCenterPoint(), 0, degree ,0);
					}
				}
			} else if(axis == 2) { // Putar di bagian kolom
				for(int i=0; i<RUBIX_COUNT; i++) {
					for(int j=0; j<RUBIX_COUNT; j++) {
						cubes[i][j][level].rotate(cubes[1][1][1].getCenterPoint(), degree, 0 ,0);
					}
				}
			} else if(axis == 3) {
				for(int i=0; i<RUBIX_COUNT; i++) {
					for(int j=0; j<RUBIX_COUNT; j++) {
						cubes[level][i][j].rotate(cubes[1][1][1].getCenterPoint(), 0, 0 ,degree);
					}
				}
			}	
			currentDegree += degree;
			if(currentDegree <= 90.0000001 && currentDegree >= 89.9999999) {
				if(currentAxis == 1) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					       cyclic_roll(cubes[j][currentLevel][i], cubes[i][currentLevel][RUBIX_COUNT-1-j], cubes[RUBIX_COUNT-1-j][currentLevel][RUBIX_COUNT-1-i], cubes[RUBIX_COUNT-1-i][currentLevel][j]);
				} else if(currentAxis == 2) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					       cyclic_roll(cubes[i][j][currentLevel], cubes[RUBIX_COUNT-1-j][i][currentLevel], cubes[RUBIX_COUNT-1-i][RUBIX_COUNT-1-j][currentLevel], cubes[j][RUBIX_COUNT-1-i][currentLevel]);		
				} else if(currentAxis == 3) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					       cyclic_roll(cubes[currentLevel][i][j], cubes[currentLevel][RUBIX_COUNT-1-j][i], cubes[currentLevel][RUBIX_COUNT-1-i][RUBIX_COUNT-1-j], cubes[currentLevel][j][RUBIX_COUNT-1-i]);
				}
				currentAxis = 0;
				currentDegree = 0;
				currentLevel = 0;
			} else if(currentDegree >= -90.0000001 && currentDegree <= -89.9999999) {
				if(currentAxis == 1) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					       cyclic_roll(cubes[i][currentLevel][j], cubes[RUBIX_COUNT-1-j][currentLevel][i], cubes[RUBIX_COUNT-1-i][currentLevel][RUBIX_COUNT-1-j], cubes[j][currentLevel][RUBIX_COUNT-1-i]);
				} else if(currentAxis == 2) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					   		cyclic_roll(cubes[j][i][currentLevel], cubes[i][RUBIX_COUNT-1-j][currentLevel], cubes[RUBIX_COUNT-1-j][RUBIX_COUNT-1-i][currentLevel], cubes[RUBIX_COUNT-1-i][j][currentLevel]);	
				} else if(currentAxis == 3) {
					for(int i=0; i<RUBIX_COUNT/2; i++)
					   for(int j=0; j<(RUBIX_COUNT+1)/2; j++)
					       cyclic_roll(cubes[currentLevel][j][i], cubes[currentLevel][i][RUBIX_COUNT-1-j], cubes[currentLevel][RUBIX_COUNT-1-j][RUBIX_COUNT-1-i], cubes[currentLevel][RUBIX_COUNT-1-i][j]);
				}
				currentAxis = 0;
				currentDegree = 0;
				currentLevel = 0;
			} else if(currentDegree >= -0.00000001 && currentDegree <=0.000000001) {
				currentAxis = 0;
				currentDegree = 0;
				currentLevel = 0;
			}
		}
	}
}

void Rubiks::cyclic_roll(Cube &a, Cube &b, Cube &c, Cube &d) {
   Cube temp = a;
   a = b;
   b = c;
   c = d;
   d = temp;
}