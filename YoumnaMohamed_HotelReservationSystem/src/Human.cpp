#include "Entity.h"
#include "Human.h"
#include <string>
#include <iostream>
#include <Entity.h>
#include <fstream>
#include <cstring>


Human::Human()
{
    //ctor
}

Human::~Human()
{
    //dtor
}

int Human::getID()
{
    return this -> ID;
}


double Human::reserveRoom(int * humanRoomCount)
{
    int rooms;
    int nights;
    do
    {
        cout << "How many rooms would you like to reserve?" << endl;
        cin >> rooms;
        if(humanRoomCount - rooms >= 0)  // check to see if there are enough rooms
        {
            cout << "For how many nights?" << endl;
            cin >> nights;
        }
        else
        {
            cout << "There are not enough rooms." << endl;
        }
    }
    while(humanRoomCount - rooms < 0);

    *humanRoomCount -= rooms;
    return 500 * nights * rooms;
}


double Human::extendReserv()
{
    int answer;
    cout << "How many more nights?" << endl;
    cin >> answer;

    return 500 * answer;
}


void Human::addService()
{
    int answer;
    cout << "1-Dry cleaning\n2-Spa" << endl;
    cin >> answer;

    if(answer == 1)
    {
        cout << "70 is added to total cost" << endl;
    }
    else if(answer == 2)
    {
        cout << "100 is added to total cost" << endl;
    }
}


void Human::cancelReserv(int * humanRoomCount)
{
    int answer;
    cout << "Would you like to cancel reservation?\n1-Yes\n2-No" << endl;
    cin >> answer;
    if(answer == 1)
    {
        cout << "How many rooms do you want to cancel?" << endl;
        cin >> answer;
        humanRoomCount += answer; // update number of rooms with canceled rooms
    }
}
