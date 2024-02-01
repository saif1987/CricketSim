#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip>



std::string generateRandomName() {
    const std::string vowels[] ={"a","e","i","o","u"};
    
    std::string Name = "";
    for(int i=0;i<2;i++)
    {
            int numSyllables = 3+ std::rand()%3;

    while (numSyllables--) {
        const char ch = 'a' + std::rand()%('z'-'a'+1);
        Name = Name + ch + vowels[std::rand()%5];
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
    Batsman() : runsScored(0), batsmanRun(0), ballsFaced(0) {
        playerName = generateRandomName();

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

     const std::string& getPlayerName() const {
        return playerName;
    }

    // Overloaded << operator to serialize the batsman
    friend std::ostream& operator<<(std::ostream& os, const Batsman& batsman) {
        os << "Player: " << std::setw(20) << batsman.playerName << "---"
           << std::setw(10)  << batsman.batsmanRun << "(" << batsman.ballsFaced << ")";
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

// Function to display the scorecard
void displayScorecard(int overs, int ballsInOver, int totalRuns, int wickets, Batsman *batsman)
{
    std::cout << "\n=== Scorecard ===" << std::endl;
    std::cout << "Overs: " << overs << "." << ballsInOver << " | Runs: " << totalRuns << " | Wickets: " << wickets << "| Batsman: " << *batsman << std::endl;
    std::cout << "=================" << std::endl;
}

int main()
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

                if(wickets == 10) 
                {
                    break;
                }
                batsman = &batting_lineup[wickets];

            }
        }

        std::cout << "End of inning " << inning << ". Total runs: " << totalRuns << ", Wickets: " << wickets << std::endl;
    }

    std::cout << "End of the test match." << std::endl;

    return 0;
}