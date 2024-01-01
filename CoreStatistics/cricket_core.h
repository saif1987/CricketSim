#pragma once

#include<iostream>
#include <cstdint>
#include <list>

class Delivery{
    public:
        uint16_t overs;
        uint16_t ball;
};

class DeliveryResult{
    public:
        Delivery delivery;
        uint32_t run_by_batsman;
        uint32_t run_by_extra;
        bool wicket; //assuming single wicket maximum
        bool nonstriker_wicket; 
        bool strikechange;

};



class InningsScore{
    public:
        uint16_t run;
        uint8_t wickets;
        Delivery over;

};

