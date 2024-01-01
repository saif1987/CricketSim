#pragma once
#include <iostream>
#include <cstdint>
#include  "cricket_core.h"

class  Batsman{
    public:
        std::string name;
        uint8_t batting_order;
        InningsScore starting_innings_score;

        bool at_striking_end;
        uint16_t run_scored;
        uint16_t balls_faced;
    
        uint16_t fours;
        uint16_t sixes;    
};
