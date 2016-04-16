#ifndef RUBIKS_H
#define RUBIKS_H 

#include "Cube.hpp"
#define RUBIX_COUNT 3

class Rubiks {
	public :
		Rubiks();
		Rubiks(Point p, GLfloat size);
		Rubiks(const Rubiks &r);
		Rubiks& operator=(const Rubiks &r);
		~Rubiks();
		friend ostream& operator<<(ostream &out, const Rubiks &rubiks);

		Point getPosition();
		GLfloat getSize();

		void draw();

	private :
		Cube cubes[RUBIX_COUNT][RUBIX_COUNT][RUBIX_COUNT];
		Point position;
		GLfloat size;
		const Point defaultPosition;
		const GLfloat defaultSize;
};

#endif