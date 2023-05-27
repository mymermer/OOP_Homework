/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#pragma once
#include "pokemon.h"
class PsychicPokemon: public Pokemon 
{
public:
    PsychicPokemon(const string name, const int hp,const int damage);
    void set_realDamage(bool& confusedFlag );
    const int get_realDamage() const;

private:
    int realDamage{};//beside of damage, current damage can be different for a pokemon for a round
};