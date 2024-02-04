#ifndef DELIVERY_SIMULATOR_H
#define DELIVERY_SIMULATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Enumeration to represent different types of wickets
enum WicketType {
    NO_WICKET = 0,
    CAUGHT,
    BOWLED,
    HIT_WICKET,
    LBW,
    CAUGHT_AND_BOWLED,
    RETIRED_HURT,
    RUN_OUT,
    STUMPED
};

// Class to represent the outcome of a cricket delivery
class DeliveryOutcome {
public:
    uint8_t wicket_type;  // Type of wicket (enum WicketType)
    uint8_t batsman_run;  // Runs scored by the batsman
    uint8_t wide_run;     // Runs scored as wides
    uint8_t lb_run;       // Runs scored as leg byes
    uint8_t bye_run;      // Runs scored as byes
    uint8_t nb_run;       // Runs scored as no balls

    uint8_t total_extras; // Total extra runs (sum of wide, leg byes, byes, and no balls)
    uint8_t total_runs;   // Total runs (sum of extras and batsman runs)

    // Default constructor to initialize member variables
    DeliveryOutcome() : wicket_type(0), batsman_run(0), wide_run(0), lb_run(0), bye_run(0), nb_run(0), total_extras(0), total_runs(0) {}

    // Function to calculate total extras and total runs
    void calculateTotals() {
        total_extras = wide_run + lb_run + bye_run + nb_run;
        total_runs = total_extras + batsman_run;
    }

    // Function to print the outcome details
    void printOutcome() const {
        std::cout << "Wicket Type: " << static_cast<int>(wicket_type) << std::endl;
        std::cout << "Batsman Run: " << static_cast<int>(batsman_run) << std::endl;
        std::cout << "Wide Run: " << static_cast<int>(wide_run) << std::endl;
        std::cout << "Leg Bye Run: " << static_cast<int>(lb_run) << std::endl;
        std::cout << "Bye Run: " << static_cast<int>(bye_run) << std::endl;
        std::cout << "No Ball Run: " << static_cast<int>(nb_run) << std::endl;
        std::cout << "Total Extras: " << static_cast<int>(total_extras) << std::endl;
        std::cout << "Total Runs: " << static_cast<int>(total_runs) << std::endl;
    }
};

// Class to simulate cricket deliveries
class Simulator {
private:
    std::random_device rd;                         // Random device for seeding
    std::mt19937 gen;                              // Mersenne Twister 19937 generator
    std::uniform_real_distribution<double> dis;    // Uniform distribution for random values

public:
    // Constructor to initialize random number generator
    Simulator() : gen(rd()), dis(0.0, 1.0) {}

    // Function to simulate a cricket delivery based on given probabilities
    size_t simulateDelivery(const std::vector<double> &probabilities, const std::string &category) {
        double random_value = dis(gen);
        double cumulative_probability = 0.0;

        // Iterate through probabilities to determine the outcome index
        for (size_t i = 0; i < probabilities.size(); ++i) {
            cumulative_probability += probabilities[i];
            if (random_value <= cumulative_probability) {
                // Return the outcome index
                return i;
            }
        }
        // Default case
        return 0;
    }
};

// Function to encapsulate delivery simulation logic
DeliveryOutcome DeliverySimulator();

#endif // DELIVERY_SIMULATOR_H
