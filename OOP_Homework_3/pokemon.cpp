/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#include "pokemon.h"


Pokemon::Pokemon(const string n, const int d, const int pupc,const int rch) : name{n},damage{d}, powerUp_chance{pupc}, recharge{rch} {
    remaingTimeToPowerUp = recharge; //prefer to initilize this in function body
};

const string Pokemon::get_name() const{
    return name;
}

const int Pokemon::get_hit_points() const {
    return hit_points;
}

void Pokemon::set_hit_points(const int in){
    hit_points = in;
}
void Pokemon::decrease_hit_points_by(const int in){//decrease hit point by a number
    hit_points -= in;
    if(hit_points<0)//prevent it to decrease less than 0
        hit_points = 0;
}

//decide operation made in arena, this function just makes assignment
void Pokemon::set_terrain(bool in){
    inTerrain = in;
}

bool const Pokemon::get_terrain() const{
    return inTerrain;
}

void Pokemon::set_powerUp(bool in){
    inPowerUp = in;
}

bool const Pokemon::get_powerUp() const{
    return inPowerUp;
}

int const Pokemon::get_damage() const{
    return damage;
}

void Pokemon::increase_remaingTimeToPowerUp(){//increase by 1
    remaingTimeToPowerUp++;
}

void Pokemon::decrease_remaingTimeToPowerUp(){//decrease by 1
    remaingTimeToPowerUp--;
}
const bool Pokemon::isremaingTimeToPowerUpZero(){
    return remaingTimeToPowerUp == 0;
}
void Pokemon::reset_remaingTimeToPowerUp(){
    remaingTimeToPowerUp = recharge+1; //including power up time
}

const int Pokemon::get_powerUp_chance() const{
    return powerUp_chance;
}

const bool Pokemon::faintCheck(){
    if (hit_points<=0){
        isFainted = true; 
        return true;
    }
    return false;
}