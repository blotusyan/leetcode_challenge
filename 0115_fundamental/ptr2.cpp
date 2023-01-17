#include <iostream>
using namespace std;

// Shape class with a constructor and protected member variables
class Shape {
public:
  Shape(int width = 0, int height = 0) {  // Constructor
    this->width = width;
    this->height = height;
  }
protected:
  int width;
  int height;
};

// Triangle class derived from Shape
class Triangle : public Shape {
public:
  Triangle(int width, int height) : Shape(width, height) {}
  int area() {  // Overrides area() function
    return width * height / 2;
  }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
public:
  Rectangle(int width, int height) : Shape(width, height) {}
  int area() {  // Overrides area() function
    return width * height;
  }
};

int main() {
  Triangle tri(2, 3);  // Creates a Triangle object with width=2 and height=3
  cout << "Triangle area: " << tri.area() << endl;

  Rectangle rec(2, 3);  // Creates a Rectangle object with width=2 and height=3
  cout << "Rectangle area: " << rec.area() << endl;

  return 0;
}
