#include "Team2.hpp"
#include <algorithm>
#include <vector>
namespace ariel
{

    Team2::Team2(Character *Leader) : Team(Leader)
    {};
    //////////////////////////////////////////////////////ATTACK TEAM2////////////////////////////////
   


    ///////////////////////////////////////////////TEST ATTACK////////////////


    void Team2::attack(TeamCenter * enemyTeam){
        if(enemyTeam==nullptr){throw invalid_argument("null");}
        if(!this->stillAlive()) return;
        if(!enemyTeam->stillAlive()){throw runtime_error("no players alive");}
        //Maybe do the whole captain change in set target? check if the captain is alive.
        if(!currentLeader->isAlive()){
            this->getNewLeader();
        }

        Character *target = enemyTeam->getTarget(currentLeader);
        if(target==nullptr) {throw runtime_error("no enemies");}

        for (auto warrior = warriors.rbegin(); warrior != warriors.rend(); ++warrior) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(*warrior)) {
                if(cowboy->isAlive()){
                if(!cowboy->hasboolets()){
                    cowboy->reload();
                }else{
                cowboy->shoot(target);
                }
                }
            } 
            
            else if (Ninja* ninja = dynamic_cast<Ninja*>(*warrior)) {
                if(ninja->isAlive()){
                if(ninja->distance(target)<1){
                ninja->slash(target);
            }else{
                ninja->move(target);
            }
                }
        }
        if(!enemyTeam->stillAlive()) return;
        if(!target->isAlive()){
                    target = enemyTeam->getTarget(currentLeader);
                    if(!target) throw runtime_error("no players");
            }
    }
    }
    ///////////////////////////////////////////////////PRINT////////////////////////

    void Team2::print()
    {
        for(Character * warrior : warriors){
            cout << warrior << endl;
        }
    };

}
