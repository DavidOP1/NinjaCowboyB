#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>
using namespace std;

namespace ariel{
class Ninja : public Character{
    protected:
        int speed , health , damage=40;
        bool captain = false ,inteam = false;
        string Name;
        Point currentLocation;
    public:
        Ninja(int ninjaSpeed , Point location , int hp , string Name);
        int getHealth();
        void move(Character * enemy);
        void slash(Character * enemy);

        //Interface functions:
        void setTeam(bool) override;
        bool inTeam() override;
        bool isCaptain() override;
        void setCaptain(bool) override;
        bool isAlive() override;
        double distance(Character * player) override;
        void hit(int damage) override;
        string getName() override;
        Point getLocation() const override;
        string print() override;
};
}
#endif //NINJA_HPP