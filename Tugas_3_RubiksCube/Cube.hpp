#include "Square.hpp"

class Cube{
	public:
		//static
		static const int SIDE;
		
		//methods
		Cube();
		Cube(Square squares[6]);
		Cube(Point center, GLfloat side, Color colors[6]);
		friend ostream& operator<<(ostream &out, const Cube &P);
		
		Point getCenterPoint();
		Color getColorAt(int index);
		void setColorAt(int index, Color color);
		Square getSquareAt(int index);
		void setSquareAt(int index, const Square S);
		void draw();
		void drawOutline();
		void rotate(Point origin, float alpha, float beta, float gamma);
	private:
		//attribute
		Square squares[6];
		
};

