#include <iostream>
#include "player.h"
#include "team.h"
#include <stdlib.h>
#include <string>
void Team::setTName(const std::string &tname) { name = tname ;}
void Team::setTgoals(const int& g) { goals = g ;}
void Team::setTpasses(const int& pass) { passes = pass ;}
void Team::setTsteals(const int& steal) { steals = steal ;}
void Team::inc_passes() {passes++ ;}
void Team::inc_faults() {faults++ ;}
void Team::inc_goals() {goals++; }

std::string Team::getTName() {return name ;}
int  Team::getTgoals() {return goals ;}
int  Team::getTpasses() { return passes ;}
int  Team::getTsteals() { return steals ;}
Player * Team::getPlayer(const int& a) { return players[a];}

// έλεγχος ομάδας παίκτη

void Team::action(Ball& b, Field& f) {
    std::cout << name << std::endl ;
  for (int i = 0; i < 5 ; i++) {
    std::cout << i <<". " ;//Player * p = this->getPlayer(i) ;
    Player * p = players[i];
    int act = rand()%100 ;
    if (act < 35) {
      p->move(f,b) ;
    }else if(act < 70) {
      p->transfer(b,f);
    }else{
      p->special_move(b,f);
    }
  }
}



/*Team::Team() {
	         name = "Leicester";
	         passes =0 ;
	         faults = 0 ;
	         goals = 0 ;
	         steals = 0 ;
	         for (int i = 0 ; i < 3; i++) {
                Player* d = new Attacker(name);
                players[i] =  d;
	         }
	     }*/

Team::Team(const std::string &s)  {
    name = s ;
    passes = 0 ;
    faults = 0 ;
    goals = 0 ;
    steals = 0;
    for (int i =0 ; i < 5/2; i++) {
        Player* d = new Defender(name) ;
        players[i] = d;
    }
    for(int i = 0 ; i < 5 - 5/2 ; i++) {
        Player* d = new Attacker(name) ;
        players[5/2 + i] = d ;
    }
}
Player::Player() {}
Defender::Defender() {}
