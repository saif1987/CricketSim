
// #include <sstream>
// #include "play.h"


// Play::Play()
// {
//     std::stringstream ss;

//     std::list<std::shared_ptr<Batsman>> b_ord;
//     std::list<std::shared_ptr<Bowler>> f_ord;

//     for(int i=0; i<11; i++)
//     {
//         ss << "Batsman" <<std::to_string(i+1);
//         b_ord.push_back(std::make_shared<Batsman>(ss.str(),i+1));
//     }
//     for(int i=0; i<11; i++)
//     {
//         ss << "Bowler" <<std::to_string(i+1);
//         f_ord.push_back(std::make_shared<Bowler>(ss.str(),i+1));
//     }


//     this->current_innings = std::make_shared<Innings>("BattingTeam","FieldingTeam",b_ord,f_ord);
// }

// void Play::full_innings()
// {
//     auto innings = this->current_innings;
    

// }