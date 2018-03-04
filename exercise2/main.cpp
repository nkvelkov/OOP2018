#include <iostream>
#include <cstdio>
#include <cstring>

#include "Point.h"
#include "Robot.h"

using namespace std;

int main()
{
    Point zeroZeroPoint;
    zeroZeroPoint.Print();

    Point fiveZeroPoint(5);
    fiveZeroPoint.Print();

    Point customPoint(2, 3);
    customPoint.Print();

    Robot robot; // a call to Robot::Robot() here
    robot.Print();

    Robot testRobot(1, 2, "test"); // a call to Robot::Robot(int, int, const char*) here
    testRobot.Print();

    const int newId = 3;
    testRobot.setId(newId);

    const int newProductivity = 234;
    testRobot.setProductivity(newProductivity);

    char newRobotName[ROBO_NAME_MAX_LEN];
    strcpy(newRobotName, "newTestName");

    testRobot.setName(newRobotName);

    cout << testRobot.getId() << " " << testRobot.getProductivity() << " "
         << testRobot.getName() << endl;

    testRobot.Print();

    return 0;
}
