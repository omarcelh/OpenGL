#include "Point.hpp"
#include "Color.hpp"

class Square{
	public:
		//methods
		Square();
		Square(Point points[4], Color color);
		Square(Point p1, Point p2, Point p3, Point p4, Color color);
		friend ostream& operator<<(ostream &out, const Square &P);
		
		Color getColor();
		void setColor(Color color);
		Point getPointAt(int index);
		void setPointAt(int index, const Point P);
		void draw();
		void drawOutline();
	private:
		//attribute
		Point points[4];
		Color color;
		
		//static
		static const int CORNER;
};

