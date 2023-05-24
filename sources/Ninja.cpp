#include "Ninja.hpp"
#include <string>
using namespace std;
namespace ariel
{
    Ninja::Ninja(int ninjaSpeed, Point location, int hp, string Name) : speed(ninjaSpeed), currentLocation(location), health(hp) , Name(Name)
    {
    }

    void Ninja::setTeam(bool state){
                this->inteam=state;
    }
    bool Ninja::inTeam(){
                return inteam;
    }

    void Ninja::setCaptain(bool state){
                this->captain=state;
    }
    bool Ninja::isCaptain(){
                return captain;
    }
    
    int Ninja::getHealth()
    {
        return this->health;
    }
    void Ninja::move(Character *enemy)
    {
        currentLocation = currentLocation.moveTowards(currentLocation, enemy->getLocation(), speed);
    }
    void Ninja::slash(Character *enemy)
    {
        if(enemy==this){throw runtime_error("cant shoot yourself");}
        if(enemy&&enemy->isAlive()&&this->isAlive()){
        if (this->currentLocation.distance(enemy->getLocation()) <= 1)
        {
            // do slash here
            enemy->hit(this->damage);
        }
        }else{
            //throw error here or something
            throw runtime_error("character is dead or null");
        }
    }
    bool Ninja::isAlive()
    {
        return ((this->health) > 0) ? true : false;
    }
    void Ninja::hit(int damage)
    {
        if(damage < 0 ){
                    throw invalid_argument("negative damage");
        }
        int temp = health - damage;
        if(temp<=0){
                    this->health=0;
        }else{
                this->health -= damage;
        }
    }
    double Ninja::distance(Character *enemy)
    {
        return this->currentLocation.distance(enemy->getLocation());
    }
    string Ninja::getName()
    {
        return this->Name;
    }
    Point Ninja::getLocation() const 
    {
        return this->currentLocation;
    }
    string Ninja::print()
    {
        if (this->isAlive())
        {
            return "Name: N " + this->Name + " HP: " + to_string(this->health) + " Location: " + currentLocation.print();
        }
        else
        {
            return "(Name: N " + this->Name + ")" + " Location: " + currentLocation.print();
        }
    }
}