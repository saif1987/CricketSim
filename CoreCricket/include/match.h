#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>

#include "cricket_core.h"
#include "batsman.h"
#include "bowler.h"
#include "innings.h"

class Player
{
public:
    std::string Name;
    Player(){};
    Player(std::string name)
    {
        Name = name;
    };
    friend std::ostream& operator <<(std::ostream &os, const Player &p){
        os << p.Name;
        return os;
    };
};

class Team
{
public:
    std::string Name;
    std::vector<Player> players;
    Team(){};
    Team(std::string name, std::vector<std::string> playerNames)
    {
        Name = name;
        if (playerNames.size() != 11)
            throw std::invalid_argument("Number of Player needs to be 11");

        for (auto i : playerNames)
        {
            players.push_back(Player(i));
        }
    };
   friend std::ostream& operator <<(std::ostream &os, const Team &t){
        os << t.Name <<std::endl<<"---------------"<<std::endl;
        for(auto i : t.players)
        {
            os<<i<<std::endl;
        }
        return os;
    };

};

class Match
{
public:
    Team T1;
    Team T2;
    Match(){};
    Match(Team t1, Team t2)
    {
        T1 = t1;
        T2 = t2;
    }
    friend std::ostream& operator <<(std::ostream &os, const Match &m){
        os << m.T1 <<"_________________"<<std::endl<<m.T2<<std::endl;
        return os;
    };

private:
};
