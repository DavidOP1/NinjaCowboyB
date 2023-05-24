#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include "Team.hpp"
namespace ariel{
    class Team2 : public Team{
          public:
            Team2(Character * Leader);
            void attack(TeamCenter * enemyTeam);              
            void print();
    };
}