#ifndef TEAM_H
#define TEAM_H
#include <string>
class Player ;
class Ball;
class Field;
class Team {
    protected:
	  Player * players[5] ;
	  std::string name;
	  int faults, passes, goals, steals ;
	 public:
      //Team() ;
      Team(const std::string&) ;
      void action(Ball&,Field&) ;
      void setTName(const std::string &tname) ;
      std::string getTName() ;
      bool myTeam(Player* p) ;
      void setTgoals(const int&) ;
      int  getTgoals() ;
      void setTpasses(const int&) ;
      int  getTpasses() ;
      void setTsteals(const int&) ;
      int getTsteals() ;
    	void inc_passes() ;
    	void inc_faults() ;
    	void inc_goals() ;
      Player * getPlayer(const int&) ;
};
#endif // TEAM_H




