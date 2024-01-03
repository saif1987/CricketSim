#pragma once
#include <iostream>
#include <cstdint>
#include  "cricket_core.h"

class Batsman
{
public:
    std::string name;
    uint8_t batting_order;
    InningsScore starting_innings_score;
    std::string wicket_bowler_name;

    bool not_out;

    uint16_t run_scored;
    uint16_t balls_faced;

    uint16_t fours;
    uint16_t sixes;

    Batsman(std::string nm, uint8_t ord):name(nm),batting_order(ord),not_out(true),run_scored(0),balls_faced(0),fours(0),sixes(0){};

    friend std::ostream &operator<<(std::ostream &os, const Batsman &bat);
};
