#ifndef BALL_H
#define BALL_H
#include "player.h"
#include "field.h"
class Player ; //forward declaration
class Ball {
protected:
	int cordx,cordy;
	Player * cur_pl ;
	Player * pre_pl ; // current and previous player respectively
public:
    Player * getCurPlayer() ;
    Player * getPrePlayer() ;
    void   setCurPlayer(Player* p) ;
    void   setPrePlayer(Player* p) ;
    void rearrange(Player*) ;
    void rearrange(Field*) ;
    void setBCoords(int,int) ;
    int getBCoordx() ;
    int getBCoordy() ;
};

#endif // BALL_H


