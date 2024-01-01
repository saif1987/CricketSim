#pragma once
#include <iostream>
#include <cstdint>
#include  "cricket_core.h"
#include "batsman.h"
#include "bowler.h"
#include "innings.h"

class Play
{
    public:
        std::shared_ptr<Innings> current_innings;
        void full_innings();
        Play();

};