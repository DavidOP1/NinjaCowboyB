#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
namespace ariel{
    class OldNinja :public Ninja{
        public:
            OldNinja(string , Point);
        private: 
            const int speed = 8;
            int health = 150; 
    };
}

#endif //OLDNINJA_HPP