#pragma once
#include <iostream>
#include <cstdint>
#include "cricket_core.h"

class Batsman
{
public:
    std::shared_ptr<Player> playerinfo;
    uint8_t batting_order;
    InningsScore starting_innings_score;
    std::shared_ptr<Player> wicket_bowler;

    bool not_out;

    uint16_t run_scored;
    uint16_t balls_faced;

    uint16_t fours;
    uint16_t sixes;

    Batsman(std::shared_ptr<Player> p_info) : 
        batting_order(0), not_out(true), run_scored(0), 
        balls_faced(0), fours(0), sixes(0), playerinfo(p_info){};

    friend std::ostream &operator<<(std::ostream &os, const Batsman &bat);
};
