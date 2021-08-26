#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "Entity.h"
#include "Human.h"
#include "Monster.h"
#include "Receptionist.h"


using namespace std;
int humanRoomCount = 5;
int monsterRoomCount = 15;


bool checkID(int ID, bool * isHuman, string filename) // check to see if ID is in the actual database
{
    fstream myFile;
    myFile.open(filename, ios::in); // open file with read mode

    string line;
    while(getline(myFile, line))
    {
        char temp[line.size() + 1];
        strcpy(temp, line.c_str());
        char * token = strtok(temp, ","); // split each line in file with comma
        int i = 0;
        char * members[3];
        while(token)
        {
            members[i++] = token;
            token = strtok(NULL, ",");
        }
        if(strcmp(members[1], "Human")) // checking if member is human
        {
            *isHuman = true;
        }
        if(atoi(members[i]) == ID) // if the ID is present, return true
        {
            return true;
        }
    }
    return false;
}


int main()
{
    Receptionist * rec = new Receptionist;
    Human * human = new Human;
    Monster * monster = new Monster;
    int answer;
    int ID;
    bool isHuman = false;

    //do
    //{
        cout << "Welcome to Hotel Transylvania! Are you new here?\n1-Yes\n2-No" << endl; // greet and ask if new or not
        cin >> answer;
         //if new create account, if not ask for ID
        if(answer == 1)
        {
            rec -> createAccount("visitors.txt");
        }
        // checking to see if correct ID is given
        //do
        //{
            cout << "Enter your ID" << endl;
            cin >> ID;
       // }
       // while(!checkID(ID, &isHuman, "visitors.txt"));
        //break;
    //}
    //while(answer != 1 || answer != 2);


    // show list and get visitor answer
    cout << "1- New Reservation\n2-Extend Reservation\n3-Additional Services\n4- Cancel Reservation" << endl;
    cin >> answer;

    if(answer == 1)
    {
        if(isHuman && humanRoomCount > 0) // if the user is human, call the human class method
        {
            cout << "Amount: " << human -> reserveRoom(&humanRoomCount) << endl;
        }
        else if(!isHuman && monsterRoomCount > 0) // if not, call the monster class method
        {
            cout << "Amount: " << monster -> reserveRoom(&monsterRoomCount) << endl;
        }
        else
        {
            cout << "No rooms available" << endl;
        }
    }
    else if(answer == 2)
    {
        if(isHuman && humanRoomCount > 0) // if the user is human, call the human class method
        {
            cout << "Extra Amount: " << human -> extendReserv();
        }
        else if(!isHuman && monsterRoomCount > 0) // if not, call the monster class method
        {
            cout << "Extra Amount: " << monster -> extendReserv();
        }
    }
    else if(answer == 3)
    {
        if(isHuman) // if the user is human, call the human class method
        {
            human -> addService();
        }
        else if(!isHuman) // if not, call the monster class method
        {
            monster -> addService();
        }
        cout << "Amount added to total cost" << endl;
    }
    else if(answer == 4)
    {
        if(isHuman) // if the user is human, call the human class method
        {
            human -> cancelReserv(&humanRoomCount);
        }
        else if(!isHuman) // if not, call the monster class method
        {
            monster -> cancelReserv(&monsterRoomCount);
        }
    }
    return 0;
}




