#include "Entity.h"
#include <string>


#ifndef HUMAN_H
#define HUMAN_H


using namespace std;
class Human : public Entity
{
public:
    Human();
    ~Human();

    double reserveRoom(int * humanRoomCount); // to reserve room(s) for a number of nights

    double extendReserv(); // to extend the number of nights a room is reserved

    void addService(); // to use dry cleaning or spa

    void cancelReserv(int * humanRoomCount); // to cancel reservation

    int getID(); //getter for ID


protected:

private:
};

#endif // HUMAN_H
