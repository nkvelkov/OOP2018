#include <iostream>
#include <cstdio>
#include <cstring>

#include "Student.h"

using namespace std;

void
TestStudent()
{
    Student s; // default constructor and destructor called here.
}

int main()
{
    TestStudent();

    Student s;

    return 0;
}

/*#include "Robot.h"
#include "SmartHouse.h"
#include "DISK.h"
#include "Computer.h"

using namespace std;

int main()
{
    DISK disk;
    Computer c;

    Robot robot; // a call to Robot::Robot() here
    robot.Print();

    Robot testRobot(1, 2, "test"); // a call to Robot::Robot(int, int, const char*) here
    testRobot.Print();

    const int newId = 3;
    testRobot.setId(newId);

    const int newProductivity = 234;
    testRobot.setProductivity(newProductivity);

    char newRobotName[ROBO_NAME_MAX_LEN];
    strcpy(newRobotName, "newTestName"); // or strcpy_s(newRobotName, "newTestName"); if you are using VS.

    testRobot.setName(newRobotName);

    cout << testRobot.getId() << " " << testRobot.getProductivity() << " "
         << testRobot.getName() << endl;

    testRobot.Print();

    Robot sampleRobot(15, 72, "test2"); // a call to Robot::Robot(int, int, const char*) here

    Robot robotsArray[MAX_NUM_ROBOTS];

    robotsArray[0] = sampleRobot;
    robotsArray[1] = testRobot;
    robotsArray[2] = robot;

    const int numRobots = 3;

    // The default constructor of SmartHouse is called here
    // see the logs.
    SmartHouse sampleSmartHouse;

     Calling SmartHouse::SmartHouse(const char* address,
                                       int numRooms,
                                       int numPeople,
                                       int robotsCount,
                                       const Robot* robots);

    SmartHouse testSmartHouse("address", 3, 5, numRobots, robotsArray);

    testSmartHouse.print();

    cout << "sorting by id: "<< endl;
    testSmartHouse.sortById();

    testSmartHouse.print();

    cout << "sorting by productivity: "<< endl;
    testSmartHouse.sortByProductivity();

    testSmartHouse.print();


    return 0;
}*/

