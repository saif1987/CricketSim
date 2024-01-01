#pragma once

#include<iostream>
#include <cstdint>
#include <list>

class Delivery{
    public:
        uint16_t overs;
        uint16_t ball;
};

class InningsScore{
    public:
        uint16_t run;
        uint8_t wickets;
        Delivery over;

};

