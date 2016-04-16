#include "Point.hpp"
#include "Color.hpp"

class Square{
	public:
		//static
		static const int CORNER;
		
		//methods
		Square();
		Square(Point points[4], Color color);
		Square(Point p1, Point p2, Point p3, Point p4, Color color);
		friend ostream& operator<<(ostream &out, const Square &P);
		
		Color getColor();
		void setColor(Color color);
		Point getPointAt(int index);
		Point getCenterPoint();
		void setPointAt(int index, const Point P);
		void draw();
		void drawOutline();
		void rotate(Point origin, float alpha, float beta, float gamma);
	private:
		//attribute
		Point points[4];
		Color color;
};

