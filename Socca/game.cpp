#include "game.h"
#include <stdlib.h>
#include <string>

Game::Game()  {}

Game::Game(const std::string &ft,const std::string &st) {
    team1 = new Team(ft) ;
    team2 = new Team(st)  ;
    Ball b1 ;
}

void Game::runTurn(Field& f) {
	int order = rand()%2 ;
		if (order == 0) {
			team1->action(b1,f) ;
			team2->action(b1,f) ;
		}else{
			team2->action(b1,f) ;
			team1->action(b1,f) ;
		}
}

Ball*  Game::getBall() {return &b1 ;}

Team* Game::getTeam1() {return team1;}
Team* Game::getTeam2() {return team2;}
