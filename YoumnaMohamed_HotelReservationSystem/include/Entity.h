#include <string>

#ifndef ENTITY_H
#define ENTITY_H


using namespace std;
class Entity // general class for visitors
{
    public:
        Entity();
        ~Entity();

        //pure virtual to be implemented in subclasses
        virtual double reserveRoom(int * someCount) = 0;

        virtual double extendReserv() = 0;

        virtual void addService() = 0;

        virtual void cancelReserv(int * someCount) = 0;


    protected:
        string name;
        int ID;
        friend class Receptionist;

    private:
};

#endif // ENTITY_H
