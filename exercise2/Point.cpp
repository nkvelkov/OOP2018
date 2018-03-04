#include "Point.h"
#include <iostream>

Point::Point(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void
Point::Print()
{
    std::cout << "x= " << _x << ", y= " << _y << std::endl;
}

void
Point::SetX(int x) {
  _x = x;
}

void
Point::SetY(int y) {
  _y = y;
}

int
Point::GetX() const {
  return _x;
}

int
Point::GetY() const {
  return _y;
}
