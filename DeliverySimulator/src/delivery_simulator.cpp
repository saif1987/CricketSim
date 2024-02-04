#include "delivery_simulator.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

DeliveryOutcome DeliverySimulator() {
    Simulator simulator;
    DeliveryOutcome outcome;

    // Define the sorted outcomes and their probabilities for each category
    std::vector<double> runsProbabilities = {29616.0 / 52408.0, 15297.0 / 52408.0, 2649.0 / 52408.0, 333.0 / 52408.0, 3721.0 / 52408.0, 7.0 / 52408.0, 785.0 / 52408.0};
    std::vector<double> wicketProbabilities = {51010.0 / 52408.0, 787.0 / 52408.0, 277.0 / 52408.0, 2.0 / 52408.0, 156.0 / 52408.0, 38.0 / 52408.0, 4.0 / 52408.0, 108.0 / 52408.0, 26.0 / 52408.0};
    std::vector<double> extrasWidesProbabilities = {51172.0 / 52408.0, 1146.0 / 52408.0, 33.0 / 52408.0, 13.0 / 52408.0, 2.0 / 52408.0, 42.0 / 52408.0};
    std::vector<double> extrasLegbyesProbabilities = {51874.0 / 52408.0, 439.0 / 52408.0, 47.0 / 52408.0, 3.0 / 52408.0, 43.0 / 52408.0, 2.0 / 52408.0};
    std::vector<double> extrasByesProbabilities = {52329.0 / 52408.0, 45.0 / 52408.0, 13.0 / 52408.0, 2.0 / 52408.0, 19.0 / 52408.0};
    std::vector<double> extrasNoBallsProbabilities = {52216.0 / 52408.0, 190.0 / 52408.0, 2.0 / 52408.0};

    // Simulate a wicket delivery
    size_t wicketIndex = simulator.simulateDelivery(wicketProbabilities, "Wicket");

    // Check conditions based on the wicket outcome
    if (wicketIndex == RUN_OUT || wicketIndex == RETIRED_HURT) {
        // std::cout << "Wicket type is Run Out or Retired Hurt, limiting further processing to index 3." << std::endl;

        // Create a subset of runsProbabilities vector up to index 3
        std::vector<double> runsSubset(runsProbabilities.begin(), runsProbabilities.begin() + 3);

        // Simulate deliveries for each category up to index 3
        size_t runsIndex = simulator.simulateDelivery(runsSubset, "RunsSubset");
        // Use the indices for further processing if needed
        // Extras can happen in this case. But ignoring..
        // ...
        outcome.wicket_type = static_cast<uint8_t>(wicketIndex);
        outcome.batsman_run = static_cast<uint8_t>(runsIndex);

    } else if (wicketIndex != 0) {
        outcome.wicket_type = static_cast<uint8_t>(wicketIndex);
    } else // NOT Wicket
    {

        // std::cout << "No wicket, continuing with other probabilities." << std::endl;
        size_t extrasWidesIndex = simulator.simulateDelivery(extrasWidesProbabilities, "Extras - Wides");
        if (extrasWidesIndex > 0)
        {
            outcome.wide_run = static_cast<uint8_t>(extrasWidesIndex);
        }
        else
        {
            size_t extrasNoBallIndex = simulator.simulateDelivery(extrasNoBallsProbabilities, "Extras - No Balls");
            if (extrasNoBallIndex > 0)
            {
                outcome.nb_run = static_cast<uint8_t>(extrasNoBallIndex);
            }
            else
            {

                size_t extrasByesIndex = simulator.simulateDelivery(extrasByesProbabilities, "Extras - Byes");
                if (extrasNoBallIndex > 0)
                {
                    outcome.bye_run = static_cast<uint8_t>(extrasByesIndex);
                }
                else
                {
                    size_t runsIndex = simulator.simulateDelivery(runsProbabilities, "Runs");
                    if (runsIndex < 3)
                    {
                        size_t extrasLegbyesIndex = simulator.simulateDelivery(extrasLegbyesProbabilities, "Extras - Leg Byes");
                        outcome.lb_run = static_cast<uint8_t>(extrasLegbyesIndex);
                    }
                    outcome.batsman_run = static_cast<uint8_t>(runsIndex);
                }
            }
        }
    }
    // If wicket type is Run Out or Retired Hurt, limit further processing to index 3
    outcome.calculateTotals();
    // outcome.printOutcome();

    return outcome;
}

int main()
{
    int runs =0;
    int wickets=0;
    int over=0;
    int ball=0;
    while(wickets<10)
    {
        DeliveryOutcome outcome = DeliverySimulator();
        runs+=outcome.total_runs;
        if(outcome.wicket_type)
        {
            wickets ++;
        }
        if( !outcome.nb_run && !outcome.wide_run)
        {
            ball++;
            if(ball==6)
            {
                ball=0;
                over++;
                std::cout<<over<<"."<<ball<<" : "<<runs<<"/"<<wickets<<std::endl;
            }

        }
        
    }

    return 0;
}