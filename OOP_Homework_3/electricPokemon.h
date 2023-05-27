/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#pragma once
#include "pokemon.h"
class ElectricPokemon :public Pokemon
{
public:
    ElectricPokemon(const string name,const  int hp, const int damage);
    void set_realDamage();

    //be confused if it can be confused
    void confuse(const bool);
    
    //AKA: get_realDamage
    const int electrocution() const; 

private:
    bool confused{false}; //can be confused
    int remainingConfuse{}; // number of rounds until confussion ends
    int realDamage{}; //beside of damage, current damage can be different for a pokemon for a round
};
