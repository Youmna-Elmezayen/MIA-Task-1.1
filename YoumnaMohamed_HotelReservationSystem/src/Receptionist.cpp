#include "Receptionist.h"
#include "Entity.h"
#include "Human.h"
#include "Monster.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


Receptionist::Receptionist()
{
    //ctor
}

Receptionist::~Receptionist()
{
    //dtor
}

int Receptionist::generateID(string filename)
{
    int max;
    max = 20; //set the upper bound to generate the random number
    int tempID = rand()%max;
    fstream myFile;
    myFile.open(filename, ios::in); //opens file for checking if ID is unique

    string line;
    while(getline(myFile, line)) // read till end of file
    {
        char temp[line.size() + 1];
        strcpy(temp, line.c_str());
        char *token = strtok(temp, ","); // get into file and split with commas
        char * members[3];
        int i = 0;
        while (token) // take every token and place in members
        {
            members[i++] = token;
            token = strtok(NULL,",");
        }
        if(atoi(members[2]) == tempID)  //check to see if the ID is repeated
        {
            tempID = generateID(filename);
        }
    }
    myFile.close();
    return tempID;
}


void Receptionist::createAccount(string filename)
{
    string name;
    int type;
    int ID = generateID(filename); // generating ID for new visitor

    cout << "What is your name?" << endl; // asking visitor for name
    cin >> name;
    cout << "What are you?\n1- Human\n2-Monster" << endl;
    cin >> type;
    if(type == 1)
    {
        fstream myFile;
        myFile.open(filename, ios::app); // write in file with new info
        myFile << name << "," << "Human" << "," << ID << endl;
        myFile.close();
    }
    else if (type == 2)
    {
        fstream myFile;
        myFile.open(filename, ios::app); // write in file with new info
        myFile << name << "," << "Monster" << "," << ID << endl;
        myFile.close();
    }
    cout << "Your Login ID is: " << ID << endl;
}
