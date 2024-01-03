#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>

#include  "cricket_core.h"
#include "batsman.h"
#include "bowler.h"
#include "innings.h"

class Player{
public: 
    std::string Name;
    Player(){};
    Player(std::string name){
        Name = name;
    };
};

class Team{
public:
    std::string Name;
    std::vector<Player> players;
    Team(){};
    Team(std::string name, std::vector< std::string > playerNames){ 
        Name = name;
        if(playerNames.size()!=11)
            throw std::invalid_argument("Number of Player needs to be 11");

        for(auto i: playerNames)
        {
            players.push_back(Player(i));
        } 
    };
};


class Match{
public:
    Team T1;
    Team T2;
    Match(){};
    Match(Team t1, Team t2){
        T1 = t1;
        T2 = t2;
    }
private:
};

