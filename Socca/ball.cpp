#include <iostream>
#include "ball.h"

void Ball::setCurPlayer(Player * p) { cur_pl = p ;}
void Ball::setPrePlayer(Player * p) { pre_pl = p ;}

Player *  Ball::getCurPlayer() {return cur_pl;}
Player * Ball::getPrePlayer() {return pre_pl;}


void Ball::rearrange(Field* f) {
      if(cur_pl == nullptr) {
        int c = 0 ;
        for(int i = cordx - 1 ; i <= cordx + 1 ; i++) {
            if(i >= 0 && i < 10) {
            for(int j = cordy - 1 ; j <= cordy + 1 ; j++ ) {
                if(j >= 0 && j < 8) {
                    if (f->getFPlayer(i,j)!=nullptr) {
                        f->setBall(cordx,cordy,false) ;
                        cur_pl = f->getFPlayer(i,j) ;
                        cordx = i ;
                        cordy = j ;
                        f->setBall(cordx,cordy,true) ;
                        c = 1 ;
                        std::cout << cur_pl->getPName() << " (" << i << "," << j << ") took the ball!" << std::endl ;
                        //break;
                    }
                } // end if width
        if(c == 1) { j = cordy + 2 ;}
        } //end for j
        } // end if(height)
        if(c == 1) { i = cordx + 2 ;}
      } // end for i
    } //end if !=null
}

void Ball::rearrange(Player* p) {
  /*if (cur_pl == nullptr) {
    if (t1.myTeam(getCurPlayer())) {
	       if(t1.myTeam(b1.getPrePlayer())) {
	         t1.inc_passes();
          }
          else { t1.inc_faults() ;}
        }else{
	       if(t2.myTeam(b1.getPrePlayer())) {
	         t2.inc_passes();
          }
        else{
    	   t2.inc_faults();
        }
        }

  } */
}


 void Ball::setBCoords(int x, int y) {
      cordx = x ;
      cordy = y ;
    }


int  Ball::getBCoordx() {return cordx ;}
int  Ball::getBCoordy() {return cordy ;}
