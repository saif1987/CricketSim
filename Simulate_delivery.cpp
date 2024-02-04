#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

enum WicketType {
    NO_WICKET,
    CAUGHT,
    BOWLED,
    HIT_WICKET,
    LBW,
    CAUGHT_AND_BOWLED,
    RETIRED_HURT,
    RUN_OUT,
    STUMPED
};

int main() {
    // Define the sorted outcomes and their probabilities for each category
    std::vector<double> runsProbabilities = {29616.0 / 52408.0, 15297.0 / 52408.0, 2649.0 / 52408.0, 333.0 / 52408.0, 3721.0 / 52408.0, 7.0 / 52408.0, 785.0 / 52408.0};
    std::vector<double> wicketProbabilities = {51010.0 / 52408.0, 787.0 / 52408.0, 277.0 / 52408.0, 2.0 / 52408.0, 156.0 / 52408.0, 38.0 / 52408.0, 4.0 / 52408.0, 108.0 / 52408.0, 26.0 / 52408.0};
    std::vector<double> extrasWidesProbabilities = {51172.0 / 52408.0, 1146.0 / 52408.0, 33.0 / 52408.0, 13.0 / 52408.0, 2.0 / 52408.0, 42.0 / 52408.0};
    std::vector<double> extrasLegbyesProbabilities = {51874.0 / 52408.0, 439.0 / 52408.0, 47.0 / 52408.0, 3.0 / 52408.0, 43.0 / 52408.0, 2.0 / 52408.0};
    std::vector<double> extrasByesProbabilities = {52329.0 / 52408.0, 45.0 / 52408.0, 13.0 / 52408.0, 2.0 / 52408.0, 19.0 / 52408.0};
    std::vector<double> extrasNoBallsProbabilities = {52216.0 / 52408.0, 190.0 / 52408.0, 2.0 / 52408.0};

    // Define a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    // Simulate a delivery for each category
    auto simulateDelivery = [&](const std::vector<double>& probabilities, const std::string& category) {
        double random_value = dis(gen);
        double cumulative_probability = 0.0;

        for (size_t i = 0; i < probabilities.size(); ++i) {
            cumulative_probability += probabilities[i];
            if (random_value <= cumulative_probability) {
                std::cout << category << " Outcome Index: " << i << std::endl;
                break;
            }
        }
    };

    // Simulate deliveries for each category
    simulateDelivery(runsProbabilities, "Runs");
    simulateDelivery(wicketProbabilities, "Wicket");
    simulateDelivery(extrasWidesProbabilities, "Extras - Wides");
    simulateDelivery(extrasLegbyesProbabilities, "Extras - Legbyes");
    simulateDelivery(extrasByesProbabilities, "Extras - Byes");
    simulateDelivery(extrasNoBallsProbabilities, "Extras - No Balls");

    return 0;
}
