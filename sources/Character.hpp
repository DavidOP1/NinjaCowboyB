#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdio.h>
using namespace std;
using namespace ariel;

class Character{
    public:
        virtual void setTeam(bool state) =0;
        virtual bool inTeam() =0;
        virtual bool isCaptain() = 0;
        virtual void setCaptain(bool state) = 0;
        virtual bool isAlive() = 0;
        virtual double distance(Character * player) = 0;
        virtual void hit(int damage) = 0;
        virtual string getName() = 0;
        virtual Point getLocation() const = 0 ;
        virtual string print() = 0;
        //virtual ~Character() {}
};

#endif // CHARACTER_HPP