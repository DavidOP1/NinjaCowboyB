#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
namespace ariel{
    class Cowboy : public Character{
        public:
            Cowboy(string , Point);
            //Interface functions
            void setTeam(bool) override;
            bool inTeam() override;
             bool isCaptain() override;
             void setCaptain(bool) override;
            bool isAlive() override;
            double distance(Character* player) override;
            void hit(int damage) override;
            string getName() override;
            Point getLocation() const override;
            string print() override;

            //Cowboy functions
            void shoot(Character *);
            bool hasboolets();
            void reload();  
        private:
            int bullets = 6 , health = 110 , damage = 10;
            bool captain = false , inteam = false;
            string name;
            Point currentLocation;
        };
}

#endif //COWBOY_HPP