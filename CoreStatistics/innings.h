#pragma once

#include <iostream>
#include <cstdint>
#include <list>
#include <ostream>
#include <memory>
#include "cricket_core.h"
#include "batsman.h"
#include "bowler.h"

class Innings
{
public:
    std::string batting_team_name;
    std::string opponent_name;
    InningsScore score;
    std::list<std::shared_ptr<Batsman>> batting_order;
    std::shared_ptr<Batsman> striking_batsman;
    std::shared_ptr<Batsman> non_striking_batsman;
    std::list<std::shared_ptr<Bowler>> bowlers;
    std::shared_ptr<Bowler> current_bowler;
    std::list<InningsScore> fall_of_wickets;

    Innings(std::string b_team, std::string o_team, std::list<std::shared_ptr<Batsman>> b_ord, 
        std::list<std::shared_ptr<Bowler>> f_ord):batting_team_name(b_team),
        opponent_name(o_team),batting_order(b_ord),bowlers(f_ord){};
    
};