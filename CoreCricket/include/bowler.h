#pragma once
#include <iostream>
#include <cstdint>
#include  "cricket_core.h"

class  Bowler{
    public:
        std::string name;
        uint16_t runs_conceded;
        uint8_t wickets_scored;
        Delivery overs_bowled;
};
