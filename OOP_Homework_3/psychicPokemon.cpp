/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/

#include "psychicPokemon.h"

PsychicPokemon::PsychicPokemon(const string name, const int hp, const int damage):Pokemon(name, damage, 30, 5){
    set_hit_points(hp);
    realDamage = damage;
}

//calculate damage for current round activate power up when ok
void PsychicPokemon::set_realDamage(bool& confusedFlag){
    realDamage = get_damage()+ get_damage()*get_terrain(); //if in Psychic terrain x2 damage
    

   if (isremaingTimeToPowerUpZero() && !get_powerUp() )
    {
        if(rand() % 100 < get_powerUp_chance()){ //same logic with deciding terrain 
            set_powerUp(true);//time for power up
            reset_remaingTimeToPowerUp();
            confusedFlag = true; //confuse attack
        }
        else{
            increase_remaingTimeToPowerUp();
        }
    }
    else if(get_powerUp()){//exit from power up status
        set_powerUp(false);
        confusedFlag = false;
    }

    decrease_remaingTimeToPowerUp();
}


const int PsychicPokemon::get_realDamage() const{
    return realDamage;
}