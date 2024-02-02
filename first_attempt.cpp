#include <iostream>
#include "match.h"
#include "play.h"

int older_sim()
{
    std::cout<<"Hello"<<std::endl;

    Team t1 = Team("Team1",{
        "T1Player1","T1Player2","T1Player3","T1Player4",
        "T1Player5","T1Player6","T1Player7","T1Player8",
        "T1Player9","T1Player10","T1Player11"});

    Team t2 = Team("Team2",{
        "T2Player1","T2Player2","T2Player3","T2Player4",
        "T2Player5","T2Player6","T2Player7","T2Player8",
        "T2Player9","T2Player10","T2Player11"});

    Match match = Match(t1,t2);

    std::cout<<match<<std::endl;

    Play play=Play(&match);
    play.BothInnings();

    return 0;
}