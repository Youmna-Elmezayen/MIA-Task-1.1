#include "Entity.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include <Entity.h>

Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}

int Monster::getID()
{
    return this -> ID;
}


double Monster::reserveRoom(int * monsterRoomCount)
{
    int rooms;
    int nights;
    do
    {
        cout << "How many rooms would you like to reserve?" << endl;
        cin >> rooms;
        if(monsterRoomCount - rooms >= 0) // check to see if there are enough rooms
        {
            cout << "For how many nights?" << endl;
            cin >> nights;;
        }
        else
        {
            cout << "There are not enough rooms. Enter another number" << endl;
        }
    }
    while(monsterRoomCount - rooms < 0);

    *monsterRoomCount -= rooms;
    return 200 * nights * rooms;
}


double Monster::extendReserv()
{
    int answer;
    cout << "How many more nights?" << endl;
    cin >> answer;

    return 200 * answer;
}


void Monster::addService()
{
    int answer;
    cout << "1-Dry cleaning\n2-Spa" << endl;
    cin >> answer;

    if(answer == 1)
    {
        cout << "30 is added to total cost" << endl;
    }
    else if(answer == 2)
    {
        cout << "50 is added to total cost" << endl;
    }
}


void Monster::cancelReserv(int * monsterRoomCount)
{
    int answer;
    cout << "Would you like to cancel reservation?\n1-Yes\n2-No" << endl;
    cin >> answer;
    if(answer == 1)
    {
        cout << "How many rooms do you want to cancel?" << endl;
        cin >> answer;
        monsterRoomCount += answer; // update number of rooms with canceled rooms
    }
    }
}
