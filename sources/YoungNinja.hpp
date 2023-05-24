#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Ninja.hpp"
namespace ariel{
    class YoungNinja : public Ninja{
        public:
            YoungNinja(string , Point);
        private:
            const int speed = 14;
            int health = 100;
    };
}

#endif //YOUNGNINJA_HPP