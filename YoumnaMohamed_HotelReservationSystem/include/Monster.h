#include "Entity.h"
#include <string>

#ifndef MONSTER_H
#define MONSTER_H

class Monster : public Entity
{
    public:
        Monster();
        ~Monster();

    double reserveRoom(int * monsterRoomCount); // to reserve room(s) for a number of nights

    double extendReserv(); // to extend the number of nights a room is reserved

    void addService(); // to use dry cleaning or spa

    void cancelReserv(int * monsterRoomCount); // to cancel reservation

    int getID(); //getter for ID

    protected:

    private:
};

#endif // MONSTER_H
