/* @Author
* Student Name: Muhammed Yusuf Mermer
* Student ID : 150220762
*/
#pragma once
#include "electricPokemon.h"
#include "psychicPokemon.h"
#include <cstdlib>
using std::srand;//srand called for main.cpp

class Arena
{
public:
    //all the methods and attributes requried for this class already specified in question pdf
    //check regarding cpp for explainations
    void addPokemon(const char type, const string name,const int hp, const int damage);
    void restartTerrain();
    const string spawnTerrain();
    void simulateBattle();
    void printRoundStats(const int round, const int heads) const;
    void printMatchResults() const;


private:
    ElectricPokemon *e{nullptr};
    PsychicPokemon *p{nullptr};
    string currentTerrain;//current terrain in the battle
};