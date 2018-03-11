#ifndef SMARTHOUSE_H
#define SMARTHOUSE_H

#include "Robot.h"

const int MAX_NUM_ROBOTS = 20;
const int ADDRESS_MAX_LEN = 11;

class SmartHouse
{
    public:
        SmartHouse();
        SmartHouse(const char* address,
                   int numRooms,
                   int numPeople,
                   int robotsCount,
                   const Robot* robots);

        const char* getAddress() const;
        int getNumRooms() const;
        int getNumPeople() const;
        int getNumRobots() const;
        const Robot* getRobots() const;

        void setAddress(const char* address);
        void setNumRooms(int numRooms);
        void setNumPeople(int numPeople);
        void setRobots(int robotsCount, const Robot* robots);

        void print() const;

        void sortById();
        void sortByProductivity();

    private:
        char  _address[ADDRESS_MAX_LEN];
        int   _numRooms;
        int   _numPeople;
        int   _robotsCount;
        Robot _robots[MAX_NUM_ROBOTS];
};

#endif // SMARTHOUSE_H
