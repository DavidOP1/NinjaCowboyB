#include "Team.hpp"
#include <algorithm>
#include <vector>
#include "Team2.hpp"
namespace ariel
{

    Team::Team(Character *Leader) 
    {
        if (Leader && !Leader->isCaptain() && Leader->isAlive())
        {
            this->currentLeader = Leader;
            this->add(Leader);
            Leader->setCaptain(true);
        }else{
            throw runtime_error("team constructor error");
        }
    };
   
    //-------------------------------------------ATTACK TEAM2----------------------------//

    //--------------------------------------------ADD------------------------------------//
    void Team::attack(TeamCenter *enemyTeam)
    {
        if(enemyTeam==nullptr){throw invalid_argument("null");}
        if(!stillAlive() || !enemyTeam->stillAlive()){throw runtime_error("no players alive");}
        //Maybe do the whole captain change in set target? check if the captain is alive.
        if(!currentLeader->isAlive()){
            this->getNewLeader();
        }
        if(!this->stillAlive()) return;
        Character *target = enemyTeam->getTarget(currentLeader);
        if(target==nullptr) {throw runtime_error("no enemies");}

        for(Character * warrior : warriors){
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(warrior)) {
                if(cowboy->isAlive()){
                if(!cowboy->hasboolets()){
                    cowboy->reload();
                }else{
                cowboy->shoot(target);
                }
                }
                if(!enemyTeam->stillAlive()) return;
                if(!target->isAlive()){
                    target = enemyTeam->getTarget(currentLeader);
                    if(!target) throw runtime_error("no players");
                }

            }
            }


        for(Character * warrior : warriors){
            if (Ninja* ninja = dynamic_cast<Ninja*>(warrior)) {
            if(ninja->isAlive()){
            if(ninja->distance(target)<1){
            ninja->slash(target);
            }else{
                ninja->move(target);
            }
            }
            if(!enemyTeam->stillAlive()) return;
            if(!target->isAlive()){
                    target = enemyTeam->getTarget(currentLeader);
                    if(!target) throw runtime_error("no players");
            }
        }
        }
        }

    //--------------------------------------------ADD------------------------------------//
    void Team::print()
    {
        for(Character * warrior : warriors){
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(warrior)) {
                cout << cowboy->print() << endl;
            }
        }


        for(Character * warrior : warriors){
            if (Ninja* ninja = dynamic_cast<Ninja*>(warrior)) {
                cout << ninja->print() << endl;
            }

        }
        }


    




    ////////////////////////////////////FUNCTIONS FOR TEAM , TEAM2 , SMART TEAM///////////////////////////
     int Team::stillAlive()
    {
        int alive = 0;
        for (Character *warrior : warriors)
        {
            if (warrior->isAlive())
                alive += 1;
        }
        return alive;
    };


    //--------------------------------------------ADD------------------------------------//
    void Team::add(Character *player)
    {
        if(!player->inTeam()){
        if (warriors.size() < 10 && warriors.size() >= 0 && player)
        {
            warriors.push_back(player);
            player->setTeam(true);
        }
        else
        {
            // throw error or basically do nothing.
            throw runtime_error("over 10 players");
        }
        }else{
            throw runtime_error("player already in team");
        }
    };

    //--------------------------------------------ADD------------------------------------//
    void Team::setLeader(Character *leader)
    {
        this->currentLeader = leader;
    }

    
    //--------------------------------------------ADD------------------------------------//
    Character * Team::getLeader()
    {
        return this->currentLeader;
    }

    ///////////////////////////////////////////GET TARGET//////////////////////////////////

    Character * Team::getTarget(Character * enemyLeader){
        this->sortWarriors(enemyLeader);
        for(Character * warrior : warriors){
            if(warrior->isAlive()){
                return warrior;
            }
        }
        return nullptr;
    }
    //------------------------------------GET NEW LEADER---------------------------------//
    void Team::getNewLeader(){
        this->sortWarriors(currentLeader);
        bool first = true , alive;
        //Choose new leader if the current one is dead
        if(!currentLeader->isAlive()){
            for(Character * warrior : warriors){
                if(warrior->isAlive()&&!first){
                    currentLeader->setCaptain(false);
                    this->setLeader(warrior);
                    warrior->setCaptain(true);
                    alive = true;
                    return;
                }
                if(first) first=false;
            }
        }
        if(!alive){
            throw runtime_error("no players alive");
        }
    }
    

    // Example usage
    void Team::sortWarriors(Character* player) {
    sort(warriors.begin(), warriors.end(), [player](Character* a, Character* b) {
        return a->distance(player) < b->distance(player);
    });
    // for(Character * warrior : warriors){
    //     cout << warrior->getLocation().print() << endl;
    // }
}
}
