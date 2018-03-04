#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "Point.h"

// Note: in C++ const objects have internal linkage by default.
// In a C header you should write static const int ROBO_NAME_MAX_LEN = 41;
const int ROBO_NAME_MAX_LEN = 41;

class Robot {
public:
    Robot();
    Robot(int id, int productivity, const char* name);

    void setId(int id);
    void setProductivity(int productivity);
    void setName(const char* name);

    int getId() const;
    int getProductivity() const;

    const char* getName() const;

    void Print() const;

private:
   int  _id;
   int  _productivity;
   char _name[ROBO_NAME_MAX_LEN];
};

#endif // ROBOT_H_INCLUDED
