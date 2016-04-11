#include "Cube.hpp"

class Cube{
	public:
		//methods
		Cube();
		Cube(Square squares[6], Color color);
		friend ostream& operator<<(ostream &out, const Cube &P);
		
		Color getColor();
		void setColor(Color color);
		Point getPointAt(int index);
		void setPointAt(int index, const Point P);
		void draw();
		void drawOutline();
	private:
		//attribute
		Square squares[6];
		Color color;
		
		//static
		static const int SIDE;
};

