#include <iostream>
using namespace std;

class Shape{
public:
  Shape(int width, int height){
    this->width = width;
    this->height = height;
  }
protected:
  unsigned int width;
  int height;
};

class Triangle : public Shape {
public:
  Triangle(int width, int height) : Shape(width, height) {}
  int getArea(){
    return width * height * 1 / 2;
  }
};

class Rectangle : public Shape {
public:
  Rectangle(int width, int height) : Shape(width, height) {}
  int getArea(){
    return this->width * this->height;
  }
};

int main(){
  Triangle* ptr = new Triangle(2,2);
  int area = ptr->getArea();
  cout << "tri area is : " << area << endl;

  Rectangle my_obj2 = Rectangle(3,3);
  int area2 = my_obj2.getArea();
  cout << "rec area is : " << area2 << endl;
  return 0;
}