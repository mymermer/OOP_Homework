/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#include "arena.h"
#include <iostream>
using std ::cerr;
using std::cout;
using std::endl;
using std::rand;


void Arena::addPokemon(const char type, const string name, const int hp, const int damage)
{
    if (type == 'p')
    {
        if (p!=nullptr) //control to prevent memory leak
            delete p;
        p = new PsychicPokemon(name, hp, damage);

        cout << "Psychic Pokemon "<<name <<" has entered the arena." << endl;
        cout << "Class: Psychic" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl<<endl<<endl;

        restartTerrain(); //restart terrain whenever a pockemon added
    }
    else if (type == 'e')
    {
        if (e!=nullptr) //control to prevent memory leak
            delete e;
        e = new ElectricPokemon(name, hp, damage);

        cout << "Electric Pokemon "<< name <<" has entered the arena." << endl;
        cout << "Class: Electric" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl<<endl<<endl;

        restartTerrain(); //restart terrain whenever a pockemon added
    }
    else
        cerr << "cannot take other values than p and e.\n"; //give error output to console

}

//only difference between restartTerrain and spawnTerrain is restartTerrain doesn't have return value
void Arena::restartTerrain(){ 
    spawnTerrain();
}

//At first, take mod 100 of number coming from rand(). 
//Result will be random between 0 and 99.
// Therfore, numbers between 0-59 (60 numbers) will be the %60 of the all random numbers.
// rand()%100<60 will return true for %60 of the time
//if it returns false, this time %50 of the time it is electric and %50 of the time psychic.  
const string Arena::spawnTerrain(){
    if(rand()%100<60){//none
        if (e!= nullptr) e->set_terrain(false);//informing pokemon about terrain
        if (p!= nullptr) p->set_terrain(false);//informing pokemon about terrain
        return "none";
    }
    else if(rand()%2==1){//electric
        if (e!= nullptr) e->set_terrain(true);//informing pokemon about terrain
        if (p!= nullptr) p->set_terrain(false);//informing pokemon about terrain
        return "electric";
    }
    else{//psychic
        if (p!= nullptr) p->set_terrain(true);//informing pokemon about terrain
        if (e!= nullptr) e->set_terrain(false);//informing pokemon about terrain
        return "psychic";
    }
}



//main loop for battles between pokemons
void Arena::simulateBattle(){
    if(p==nullptr || e==nullptr){
        cerr << "one PsychicPokemon and one ElectricPokemon have to be in the arena" << endl;
        return;
    }

    int i=0; //used to count round number
    bool confusedFlag=false; //check power up of psychic pokemons
    
    while (e->get_hit_points() > 0 && p->get_hit_points() > 0) //finish if one of hp=0
    {
        if (0 == i % (5-4*((currentTerrain=="none")?1:0))) //refresh terrain every 5 rounds (for none every time)
        {
            currentTerrain=spawnTerrain();
        }

        
        int heads = (int)(rand() % 2 == 0);//if heads=1 ->p, otherwise e
        if (heads)
        { // p hits
            
            p->set_realDamage(confusedFlag);//calcuate damage for this round
            
            e->decrease_hit_points_by(p->get_realDamage());
            if(!e->faintCheck()) {//if fainted, cannot strike
        
                e->confuse(confusedFlag); //if confuse attack happened, conufuse e
                confusedFlag = false;
                e->set_realDamage();//calcuate damage for this round
                
                p->decrease_hit_points_by(e->electrocution());
                p->faintCheck();
            }
        }
        else{// e hits

              e->set_realDamage();//calcuate damage for this round
              p->decrease_hit_points_by(e->electrocution());
              if(!p->faintCheck()) {//if fainted, cannot strike

                  p->set_realDamage(confusedFlag);
                  e->confuse(confusedFlag);//if confuse attack happened, conufuse e
                  confusedFlag = false;
                  e->decrease_hit_points_by(p->get_realDamage());
                  e->faintCheck();
              }
        }

        printRoundStats(i, heads);
        i++;
    }
    printMatchResults();

    delete e;
    delete p;
    p = nullptr;
    e = nullptr;
}


void Arena::printRoundStats(const int round, const int heads) const {
        cout <<"Round: "<< round + 1 << endl;
        cout << "Current Terrain: " << currentTerrain << endl;
        if((bool)(heads))
            cout << p->get_name() << " goes first." << endl;
        else
            cout << e->get_name() << " goes first." << endl;
        
        if((bool)(heads)){
            if(p->get_powerUp())
              cout << p->get_name() << " has initiated a power up." << endl;
            if(!e->faintCheck() && e->get_powerUp()){
                    cout << e->get_name() << " has initiated a power up." << endl;
            }

        }
        else {
            if(e->get_powerUp())
              cout << e->get_name() << " has initiated a power up." << endl;
            if(!p->faintCheck() && p->get_powerUp()){
                    cout << p->get_name() << " has initiated a power up." << endl;
            }
        }

        cout << e->get_name() << " HP: " << e->get_hit_points()<<endl;
        cout << p->get_name() << " HP: " << p->get_hit_points()<<endl;
        if (e->get_hit_points()> p->get_hit_points())
            cout << e->get_name() << " is in the lead!" << endl;
        else if (p->get_hit_points()>e->get_hit_points())
            cout << p->get_name() << " is in the lead!" << endl;
        else
            cout << p->get_name() << " and " << e->get_name() << " has same HP." << endl;
        cout << endl<< endl;    
}


void Arena::printMatchResults() const {
    cout << "Match Results: " << endl;
    if ( p->get_hit_points()<=0)
            cout << e->get_name() << " has won the match!" << endl<<endl<<endl;
    else if (e->get_hit_points()<=0)
        cout << p->get_name() << " has won the match!" << endl<<endl<<endl;
}
