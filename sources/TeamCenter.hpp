#ifndef TEAMCENTER_HPP
#define TEAMCENTER_HPP
//#include "Point.hpp"
#include "Character.hpp"
#include <vector>
using namespace std;
namespace ariel{
class TeamCenter{
    public:
        virtual int stillAlive() =0;
        virtual Character * getTarget(Character * enemyLeader) =0;
};
}
#endif // TEAMCENTER_HPP