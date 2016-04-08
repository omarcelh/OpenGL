#include "Color.hpp"

Color::Color() {
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(GLfloat r, GLfloat g, GLfloat b) {
	red = r;
	green = g;
	blue = b;
}

ostream& operator<< (ostream& stream, const Color& color) {
	stream << "(" << (float) color.red << "," << (float) color.green << "," << (float) color.blue << ")";
	return stream;
}

GLfloat Color::getRed() {
	return red;
}

GLfloat Color::getGreen() {
	return green;
}

GLfloat Color::getBlue() {
	return blue;
}

void Color::setColor(GLfloat r, GLfloat g, GLfloat b) {
	red = r;
	green = g;
	blue = b;
}

void Color::getAllColor(GLfloat& r, GLfloat& g, GLfloat& b) {
	r = red;
	g = green;
	b = blue;
}

// int main() {
// 	Color color(10,3,7);
// 	cout << color << endl;
// 	color.setColor(50,100,40);
// 	cout << color << endl;
// 	return 0;
// }
