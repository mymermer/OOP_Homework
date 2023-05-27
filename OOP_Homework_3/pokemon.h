/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#pragma once
#include <string>
using std::string; 

class Pokemon{
public:
  
    // member initilizer required ones (constants) are declered for parameters, others are left for set functions
    Pokemon(const string n, const int d, const int pupc,const int rch);
    
    //all gets are constant. unnecesarry get and set functions are avoided
    const string get_name() const; 
    const int get_hit_points() const; 
    void set_hit_points(const int);
    void decrease_hit_points_by(const int);  //after the damage decrease HP 
    void set_terrain(bool);
    bool const get_terrain() const;
    void set_powerUp(bool);
    bool const get_powerUp() const;
    const int get_damage() const;
    const int get_powerUp_chance() const;

    void decrease_remaingTimeToPowerUp(); //decreases only by one
    const bool isremaingTimeToPowerUpZero(); //checks whether remaining time to power up is zero
    void reset_remaingTimeToPowerUp(); //reset remaining time to recharge
    void increase_remaingTimeToPowerUp(); //increase remaining time to recharge (requried for a sitation)

    const bool faintCheck(); //if HP=0, faints the pokemon

private:
    const string name{}; //will not be changed in the future
    int hit_points{}; //will change
    const int damage{}; //will not be changed in the future
    const int powerUp_chance{}; //will not be changed in the future
    const int recharge{}; //will not be changed in the future
    bool isFainted{false}; //will change
    bool inPowerUp{false}; //will change
    bool inTerrain{false}; //will change
    int remaingTimeToPowerUp{}; //will change
};