#include "GL/freeglut.h"
#include "GL/gl.h"
#include "Point.hpp"
#include "Color.hpp"

class Triangle{
	public:
		//methods
		Triangle();
		Triangle(Point points[3], Color color);
		Triangle(Point p1, Point p2, Point p3, Color color);
		friend ostream& operator<<(ostream &out, const Triangle &P);
		
		Color getColor();
		void setColor(Color color);
		Point getPointAt(int index);
		void setPointAt(int index, const Point P);
		void draw();
		void drawOutline();
		void drawSierpinski(Color colorMap[], int n, int code);
		void drawSierpinski(Point &edge1, Point &edge2, Point &edge3, Color colorMap[], int n, int code);
		
		static const int SIERPINSKI_FILL;
		static const int SIERPINSKI_OUTLINE;
	private:
		//attribute
		Point points[3];
		Color color;
		
		//static
		static const int SIDE;
};

