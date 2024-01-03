#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>

#include  "cricket_core.h"
#include "batsman.h"
#include "bowler.h"
#include "innings.h"

class Player;
class Team;


class Match{
public:
    Team T1,T2;
private:


};


class Team{
public:
    std::string Name;
    Player players[11];
    Team(std::string name, std::vector< std::string > playerNames){ 
        Name = name;
        if(playerNames.size()!=11)
            throw std::invalid_argument("Number of Player needs to be 11");
        int i=0;
        for(auto pName: playerNames){
            players[i++].Name = name;
        }    
    };
};

class Player{
public: 
    std::string Name;
    Player(){};
    Player(std::string name){
        Name = name;
    }
};