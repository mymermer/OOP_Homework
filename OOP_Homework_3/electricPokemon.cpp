/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/

#include "electricPokemon.h"


ElectricPokemon::ElectricPokemon(const string name,const int hp,const int damage):Pokemon(name, damage, 20, 3){
    set_hit_points(hp);
    realDamage = damage;
}

//calculate damage for current round activate power up when ok
void ElectricPokemon::set_realDamage(){
    if (remainingConfuse==0 || get_terrain()){//confuission is over or entered to electric terrain
        confused = false;
        remainingConfuse = 0;
        realDamage = get_damage();
    }

   if (isremaingTimeToPowerUpZero() && !get_powerUp() )//powerup time
    {
        if(rand() % 100 < get_powerUp_chance()){ //same logic with deciding terrain 
            set_powerUp(true);//time for power up
            reset_remaingTimeToPowerUp();
            realDamage = (get_damage()+ 2* get_damage())*!confused; //x3 damage if not confused
        }
        else{
            increase_remaingTimeToPowerUp();
        }
    }
    else if(get_powerUp()){
        set_powerUp(false);
        realDamage = (get_damage())*!confused;//return back to normal damage if not confused
    }

    decrease_remaingTimeToPowerUp();
    if (confused)
        remainingConfuse--;
}


//electric pokemon starts to confused period if in is true. (electric terrain feauture checked in set_realDamage)
 void ElectricPokemon::confuse(const bool in){
    if (in){    
        confused = true;
        remainingConfuse = 3;
        realDamage = 0;
    }
 }


 const int ElectricPokemon::electrocution() const { //AKA: get_realDamage
    return realDamage;
 }