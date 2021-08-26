#include "Human.h"
#include "Monster.h"
#include <string>
#include <vector>

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H


class Receptionist
{
    public:
        Receptionist();
        ~Receptionist();

        void createAccount(string filename); // to create account for new visitor
        int generateID(string filename); // generate unique id for new visitor

    protected:

    private:
        string name;
        string gender;
};

#endif // RECEPTIONIST_H
