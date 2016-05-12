#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "team.h"

class Game {
protected:
	Team * team1 ;
	Team * team2 ;
	Ball  b1 ;
public:
    Game() ;
    Game(const std::string&,const std::string&) ;
	int turns ;
	Ball* getBall() ;
	Team* getTeam1();
	Team* getTeam2();
	void runTurn(Field&) ;
};

#endif // GAME_H


