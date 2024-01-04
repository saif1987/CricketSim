#pragma once
#include <iostream>
#include <cstdint>
#include  "cricket_core.h"
#include "batsman.h"
#include "bowler.h"
#include "innings.h"
#include "match.h"

//For playing two innings 
class Play
{
    public:
        Match* pMatch;
        Team* pT1;
        Team* pT2;
        bool first_innings_done;
        std::shared_ptr<Innings> current_innings;
        void full_innings();
        
        void SelectBattingTeam(){
            if(!first_innings_done) 
            {
                pT1 = &(pMatch->T1);
                pT2 = &(pMatch->T2);

                std::cout<<pT1->Name<<" will bat first"<<std::endl;
            }
            else
            {
                //swap
                auto temp=pT1;
                pT1=pT2;
                pT2=pT1;
                std::cout<<pT1->Name<<" will bat now"<<std::endl;

            }
        };
        
        Play(Match *pm)
        { pMatch = pm;
          first_innings_done = false;
        };

        void BothInnings(void){
            SelectBattingTeam();
            std::cout<<pT1->Name<<" will batting is  done"<<std::endl;

            first_innings_done=true;
            SelectBattingTeam();
            std::cout<<pT1->Name<<" will batting is  done"<<std::endl;

        }


        void playinnings()
        {
                std::string b_team = pT1->Name; 
                std::string o_team = pT2->Name;
                std::vector<std::shared_ptr<Batsman>> b_ord; 
                for (auto &p: pT1->players)
                {
                    auto player_ptr = std::make_shared<Player>(p);
                    b_ord.push_back(std::make_shared<Batsman>(player_ptr));
                }
                std::vector<std::shared_ptr<Bowler>> f_ord;
                // current_innings = std::make_shared<Innings>();
        }
        


};