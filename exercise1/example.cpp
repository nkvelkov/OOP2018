#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Point {
   int _x;
   int _y;

   void Read () {
      cin >> _x >> _y;
   }

   void Print () {
      cout << "(" << _x << " " << _y << ")" << endl;
   }
};

int main()
{
    Point p;
    p._x = 3;
    p._y = 4;

    p.Read();
    p.Print();

    return 0;
}
