#pragma once

#include <iostream>
#include "cricket_core.h"



void InningsScore::ApplyDeliveryResult(const DeliveryResult res)
{
    this->run = res.run_by_batsman + res.run_by_extra;
}

