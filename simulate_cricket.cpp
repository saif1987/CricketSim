#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip>
#include <algorithm>
#include <string>

class SimulateCricket
{
public:
    bool isCharacterNotInList(char ch, const std::string &charList);
    char generateRandomCharacter();
    std::string generateRandomName();
    void displayMatchSummary(const Batsman batsmen[], int numBatsmen);
    void displayScorecard(int overs, int ballsInOver, int totalRuns, int wickets, Batsman *batsman);
    SimulateCricket();
};

bool SimulateCricket::isCharacterNotInList(char ch, const std::string &charList)
{
    return std::find(charList.begin(), charList.end(), ch) == charList.end();
}

char SimulateCricket::generateRandomCharacter()
{
    // Define the characters and their corresponding frequencies
    const char characters[] = "ETAOINSHRDLCUMFWGYBPVKXJZ";
    const double frequencies[] = {13.0, 9.1, 8.1, 7.5, 7.0, 6.7, 6.3, 6.1, 6.0, 4.3, 4.0, 2.8, 2.8, 2.4, 2.2, 2.0, 1.9, 1.7, 1.6, 1.5, 1.0, 0.8, 0.2, 0.1, 0.1, 0.1};

    // Calculate the total frequency
    double totalFrequency = 0.0;
    for (double freq : frequencies)
    {
        totalFrequency += freq;
    }

    // Generate a random number between 0 and the total frequency
    double randomValue = ((double)rand() / RAND_MAX) * totalFrequency;

    // Use a weighted random selection based on the frequencies
    double cumulativeFrequency = 0.0;
    for (size_t i = 0; i < sizeof(characters) - 1; ++i)
    {
        cumulativeFrequency += frequencies[i];
        if (randomValue <= cumulativeFrequency)
        {
            return std::tolower(characters[i]);
        }
    }

    // Default to the last character if for some reason the loop didn't return
    return std::tolower(characters[sizeof(characters) - 1]);
}

std::string SimulateCricket::generateRandomName()
{
    const std::string vowels = {"aeiou"};
    const int n_v = 5;
    std::string Name = "";
    for (int i = 0; i < 2; i++)
    {
        int numSyllables = 2 + std::rand() % 2;
        bool isfirstsyllable = true;
        while (numSyllables--)
        {
            char ch = generateRandomCharacter(); //'a' + std::rand()%('z'-'a'+1);

            Name += (isfirstsyllable) ? std::toupper(ch) : ch;
            if (std::find(vowels.begin(), vowels.end(), ch) == vowels.end())
                Name += vowels[std::rand() % n_v];
            else
                Name += generateRandomCharacter();

            isfirstsyllable = false;
        }
        Name += " ";
    }
    return Name;
}

// Batsman class
class Batsman
{
private:
    std::string playerName; // Assuming each batsman has a name
    int runsScored;
    int batsmanRun;
    int ballsFaced;

public:
    Batsman() : runsScored(0), batsmanRun(0), ballsFaced(0)
    {
        playerName = SimulateCricket::generateRandomName();
    }

    void startNewInnigs()
    {
        runsScored = (0);
        batsmanRun = (0);
        ballsFaced = (0);
    }

    int bat()
    {
        // Simulate a ball delivery for the batsman
        runsScored = rand() % 6;
        batsmanRun += runsScored;
        ballsFaced++;
        return runsScored;
    }

    int getBatsmanRuns() const
    {
        return batsmanRun;
    }

    int getBallsFaced() const
    {
        return ballsFaced;
    }

    const std::string &getPlayerName() const
    {
        return playerName;
    }

    // Overloaded << operator to serialize the batsman
    friend std::ostream &operator<<(std::ostream &os, const Batsman &batsman)
    {
        os << "Player: " << std::setw(20) << batsman.playerName << "---"
           << std::setw(10) << batsman.batsmanRun << "(" << batsman.ballsFaced << ")";
        return os;
    }
};

// Bowler class
class Bowler
{
public:
    int bowl()
    {
        // Simulate a ball delivery for the bowler
        return rand() % 6;
    }
};

// Function to display the cricket match score summary
void SimulateCricket::displayMatchSummary(const Batsman batsmen[], int numBatsmen)
{
    std::cout << "=== Cricket Match Score Summary ===" << std::endl;

    for (int i = 0; i < numBatsmen; ++i)
    {
        std::cout << batsmen[i] << std::endl;
    }

    std::cout << "===================================" << std::endl;
}
// Function to display the scorecard
void SimulateCricket::displayScorecard(int overs, int ballsInOver, int totalRuns, int wickets, Batsman *batsman)
{
    std::cout << "\n=== Scorecard ===" << std::endl;
    std::cout << "Overs: " << overs << "." << ballsInOver << " | Runs: " << totalRuns << " | Wickets: " << wickets << "| Batsman: " << *batsman << std::endl;
    std::cout << "=================" << std::endl;
}

SimulateCricket::SimulateCricket()
{
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    Batsman batting_lineup[10];
    Batsman *batsman;
    Bowler bowler;

    int totalRuns = 0;
    int wickets = 0;
    int overs = 0;
    int ballsInOver = 0;

    // Simulate a test match with 2 innings per side
    for (int inning = 1; inning <= 2; ++inning)
    {
        std::cout << "Inning " << inning << ":" << std::endl;

        // Reset variables for each inning
        totalRuns = 0;
        wickets = 0;
        overs = 0;
        ballsInOver = 0;
        batsman = &batting_lineup[wickets];
        batsman->startNewInnigs();

        while (overs < 90)
        { // Simulate a test match with a maximum of 90 overs per inning
            // Simulate a ball delivery by the bowler
            int runsScored = batsman->bat();
            // int runsConceded = bowler.bowl();

            // Display the outcome of the ball delivery
            // std::cout << "Over " << overs + 1 << "." << ballsInOver + 1 << ": ";
            if (runsScored == 0)
            {
                // std::cout << "Dot ball" << std::endl;
            }
            else
            {
                // std::cout << "Batsman scored " << runsScored << " runs" << std::endl;
                totalRuns += runsScored;
            }

            // Update overs and balls
            ballsInOver++;
            if (ballsInOver == 6)
            {
                ballsInOver = 0;
                overs++;
                // displayScorecard(overs, ballsInOver, totalRuns, wickets, batsman);
            }

            // Simulate a wicket falling randomly after 30 runs
            if (totalRuns >= 30 && std::rand() % 6 == 0)
            {
                wickets++;
                std::cout << "Wicket fallen! Batsman Run: " << *batsman << std::endl;

                if (wickets == 10)
                {
                    break;
                }
                batsman = &batting_lineup[wickets];
                batsman->startNewInnigs();
            }
        }

        std::cout << "End of inning " << inning << ". Total runs: " << totalRuns << ", Wickets: " << wickets << std::endl;
        displayMatchSummary(batting_lineup, 10);
    }

    std::cout << "End of the test match." << std::endl;

    return 0;
}