// Add these header guards to prevent redefinitions.
// See https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {
public:
// This gives us 3 different constructors:
// Point();
// Point(x);
// Point(x, y);

   Point(int x = 0, int y = 0);

   void Print();

// Setters;
   void SetX(int x);
   void SetY(int y);

// Getters
   int GetX() const;
   int GetY() const;

// hide the data:
private:
   int _x;
   int _y;
};

#endif // POINT_H_INCLUDED
