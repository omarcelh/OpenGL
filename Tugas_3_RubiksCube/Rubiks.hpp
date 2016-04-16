#ifndef RUBIKS_H
#define RUBIKS_H 

#include "Cube.hpp"
#define RUBIX_COUNT 3

class Rubiks {
	public :
		Rubiks();
		Rubiks(Point p, GLfloat size, Color* colors);
		Rubiks(const Rubiks &r);
		Rubiks& operator=(const Rubiks &r);
		~Rubiks();
		friend ostream& operator<<(ostream &out, const Rubiks &rubiks);

		Point getPosition();
		GLfloat getSize();
		void rotateSide(int rowMark, int level, GLfloat degree);
		void draw();

	private :

		void cyclic_roll(Cube &a, Cube &b, Cube &c, Cube &d);

		Cube cubes[RUBIX_COUNT][RUBIX_COUNT][RUBIX_COUNT];
		Point position;
		GLfloat size;
		int currentRowMark;
		int currentLevel;
		GLfloat currentDegree;
		GLfloat rotationState;
		const Point defaultPosition;
		const GLfloat defaultSize;
};

#endif