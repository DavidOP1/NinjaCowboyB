#ifndef TEAM_HPP
#define TEAM_HPP
//#include "Point.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp" // DONT NEED TO INCLUDE CHARACTER , BECAUSE ITS INCLUDED IN COWBOY
#include <vector>
#include "TeamCenter.hpp"
namespace ariel{
class Team : public TeamCenter{
  public:
    Team(Character * Leader);
    void attack(TeamCenter * enemyTeam);
    void print();
    //functions for team ,team2 and smartteam
    Character * getLeader();
    void add(Character * );
    int stillAlive() override;
    void sortWarriors(Character *);
    Character * getTarget(Character *) override;
    void setLeader(Character *);
    void getNewLeader();
  protected:
    Character * currentLeader;
    vector<Character *> warriors;

};
}
#endif // TEAM_HPP