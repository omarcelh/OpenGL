#ifndef RUBIKS_H
#define RUBIKS_H 

#include "Cube.hpp"

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

	private :
		Cube cubes[3][3][3];
		Point position;
		GLfloat size;
		const Point defaultPosition;
		const GLfloat defaultSize;
};

#endif