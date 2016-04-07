#include "GL/freeglut.h"
#include "GL/gl.h"
#include "Point.hpp"
#include "Color.hpp"

class Triangle{
	public:
		//Method
		Triangle();
		Triangle(Point points[3], Color color);
		Triangle(Point p1, Point p2, Point p3, Color color);
		friend ostream& operator<<(ostream &out, const Triangle &P);
		
		Color getColor();
		void setColor(Color color);
		Point getPointAt(int index);
		void setPointAt(int index, const Point P);
	private:
		//Attribute
		static const int SIDE;
		Point points[3];
		Color color;
};

