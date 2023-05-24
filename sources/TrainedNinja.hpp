#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"
namespace ariel{
    class TrainedNinja :  public Ninja{
        public:
            TrainedNinja(string , Point);
        private:
            const int speed = 12;
            int health = 120;
    };
}

#endif //TRAINEDNINJA_HPP