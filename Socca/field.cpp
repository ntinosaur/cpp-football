#include "field.h"
#include <iostream>
#include "ball.h"

Field::Field() {
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 8 ; j++){
            fplayer[i][j] = nullptr ;
            ball[i][j] = false ;
        }
    }
}

bool Field::isBall(int x, int y) { return ball[x][y] ;}

Field::~Field(){};

void Field::print_f(Team* t1, Team* t2, Ball* b){
	for (int i = 0 ; i < 10 ; i++) {
	    std::cout << '|' << ' ' ;
		for(int j = 0 ; j < 8 ; j++) {
                int c = 0 ;
			for(int w = 0 ; w < 5 ; w++) {
				Player *p1 = t1->getPlayer(w) ;
				Player *p2 = t2->getPlayer(w) ;
				if(p1->getCoordx() == i && p1->getCoordy() == j) {
				    c = 1 ;
					if(p1 == b->getCurPlayer()) {
						std::cout << 'M' ;
					}else{
						std::cout << 'm' ;
					}
				}
				if(p2->getCoordx() == i && p2->getCoordy() == j) {
				    c = 1 ;
					if(p2 == b->getCurPlayer()){
						std::cout << 'L' ;
					}else{
						std::cout << 'l' ;
					}
				}
				}
            //if(c == 1) {break ;}
            if(c == 0) {
                if(ball[i][j] == true) {//(b->getBCoordx() == i && b->getBCoordy() == j ){
						std::cout << 'O' ;
					}else{
						std::cout << '~' ;
			}
			}

        std::cout << " " ;
		} //end for j
		std::cout << '|' << std::endl ;
	}

   /*if(fplayer != nullptr) { // is there a player (safety) ?
     if(fplayer->getPTeam() == "Manchester") {
        if(ball) {
            std::cout << 'M'  ;
        }else{
            std::cout << 'm' ;
        }
    }else{
        if(ball) {
            std::cout << 'L' ;
        }else {
            std::cout << 'l' ; //Leicester
        }
    }
   }else{  //there is not a player
    if(ball) {   //is there a ball ?
        std::cout << 'O' ;
    }else{                      // there is not a ball
        std::cout << '~' ;
    }
}*/
   //std::cout << " " ;
} // end print_f


void Field::setBall(int x, int y, bool st) {ball[x][y] = st ;}
Player* Field::getFPlayer(int x, int y) { return fplayer[x][y] ;}

void Field::setFPlayer(int x, int y, Player* p) { fplayer[x][y] = p ;}
