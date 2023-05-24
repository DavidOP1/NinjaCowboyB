
#include "Cowboy.hpp"
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel{
    
            Cowboy::Cowboy(string name ,Point location){
                this->name = name;
                this->currentLocation = location;
            };
            void Cowboy::setTeam(bool state){
                this->inteam=state;
            }
            bool Cowboy::inTeam(){
                return this->inteam;
            }
            void Cowboy::setCaptain(bool state){
                this->captain=state;
            }
            bool Cowboy::isCaptain(){
                return captain;
            }
            bool Cowboy::isAlive(){
                return (this->health>0) ? true : false;
            };
            double Cowboy::distance(Character * player){
                return this->currentLocation.distance(player->getLocation());
            }
            void Cowboy::hit(int damage){
                if(damage < 0 ){
                    throw invalid_argument("negative damage");
                }
                int temp = health - damage;
                if(temp<=0){
                    this->health=0;
                }else{
                this->health -= damage;
                }
            };
            string Cowboy::getName(){return this->name;};
            Point Cowboy::getLocation() const {
                return this->currentLocation;
            };
            string Cowboy::print(){
                if(this->isAlive()){
                    return "Name: C "+this->name+" HP: "+to_string(this->health)+" Location: " + currentLocation.print();
                }else{
                    return "(Name: C "+this->name+")"+" Location: " + currentLocation.print();
                }
            };
            void Cowboy::shoot(Character * enemy){
                if(enemy==this){throw runtime_error("cant shoot yourself");}
                if(enemy&&enemy->isAlive()&&this->isAlive()){
                    if(this->hasboolets()){
                    enemy->hit(this->damage);
                    this->bullets-=1;
                    }
                }else{
                    //throw error here or something
                    throw runtime_error("character is dead or null");
                }
            };
            bool Cowboy::hasboolets(){
                return (this->bullets>0) ? true : false;
            };
            void Cowboy::reload(){
                if(!this->isAlive()){
                    throw runtime_error("cowboy is dead cant reload");
                }
                this->bullets = 6;
            }; 
}