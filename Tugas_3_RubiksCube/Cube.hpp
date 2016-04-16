#include "Square.hpp"

class Cube{
	public:
		//static
		static const int SIDE;
		
		//methods
		Cube();
		Cube(Square *squares);
		Cube(Point center, GLfloat side, Color colors[6]);
		Cube(const Cube &C);
		~Cube();
		Cube& operator=(const Cube &C);
		
		friend ostream& operator<<(ostream &out, const Cube &P);
		
		Point getCenterPoint();
		Color getColorAt(int index);
		void setColorAt(int index, Color color);
		Square getSquareAt(int index);
		void setSquareAt(int index, const Square S);
		void draw();
		void drawOutline();
		void drawBlackOutline();
		void rotate(Point origin, float alpha, float beta, float gamma);
		void move(float dx, float dy, float dz);
	private:
		//attribute
		Square *squares;
		
};

