#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ball.h"
#include "player.h"
#include <string>
#include <stdlib.h>
//void Player::setPName(char  newname) { name = newname ;}
void Player::setPNumber(int numb) { number = numb ;}
void Player::setMLine(int mline) { move_l = mline ;}
void Player::setFLine(int fline) { forw_l = fline ;}
std::string Player::getPName() {return name ;}
int Player::getPNumber() {return number ;}
int Player::getMLine() {return move_l ;}
int Player::getFLine() {return forw_l ;}
int Player::getCoordx() {return cox;}
int Player::getCoordy() {return coy;}
std::string Player::getPTeam() {return pteam ;}
void Player::setPTeam(const std::string& pt) { pteam = pt ;}
void Player::setCoordx(int i) { cox = i ;}
void Player::setCoordy(int j) { coy = j ;}
void Player::setPName(const std::string& nam) {name = nam ;}


Player::Player(const std::string &s) {
    pteam = s ;
    name="Niko" ;
    number = 8 ;
    move_l = 1 ;
    forw_l = 3 ;
    cox = 1 ;
    coy = 5 ;
}

void Player::transfer(Ball& b,Field& f) {
    std::cout << "Niko transferred the ball" ;
    //b.setCurPlayer(this) ; //dokimi
    Player * cp = b.getCurPlayer() ;
	  if (cp == this) {
        int d = rand()%8 ;
        b.setBCoords(forw_l, d) ;
        std::cout << " from (" << cox << "," << coy << ") " << "to (" << forw_l << "," << d << ")" << std::endl ;
        b.setCurPlayer(nullptr) ;
        b.setPrePlayer(this) ;
        f.setBall(cox,coy,false) ;
        f.setBall(forw_l,d,true) ;
        }
        else{
            std::cout << ". It was not very effective..." << std::endl ;
        }
}


void Player::move (Field& f,Ball& b) {
    std::cout << name <<" moved" << " from " << "(" << cox << "," << coy << "), " ;
    int d ;
    int c = 0 ;
    if (f.isBall(cox,coy) == true) {   //this player has the ball
        f.setBall(cox,coy,false) ;
        c = 1 ;
    }
    f.setFPlayer(cox,coy,nullptr)  ;
    d = 2*(rand()%2) - 1 ;

                                // -1 or +1, player moves left or right respectively
    if (coy + d >= 0 && coy + d <= 7) {  // ensuring players don't move out of bounds
        coy = coy + d ;                             // move to the opposite direction
    }
    else{                                                   // move is valid
        coy = coy - d ;                             // move to direction
    }
    f.setFPlayer(cox,coy,this) ;
    if (c == 1) { f.setBall(cox,coy,true) ;}

   std::cout << " to position (" << cox <<"," << coy << ")" << std::endl ;
}

void Defender::special_move(Ball& b,Field& f){
    std::cout << name << "'s special move : " ;
    int i, j, odds ;
    Player *cp = b.getCurPlayer() ;
    if (cp != nullptr) {
    for (i = cox -1 ; i <= cox + 1 ; i+=2) {
       if ( i >= 0 && i < 10) {
          for (j = coy - 1 ; j <= coy + 1 ; j++) {
             if (j >= 0 && j < 8) {
                if ( cp->getCoordx() == i && cp->getCoordy() == j) {
                   std::cout << "Tackle " ;
                   odds = rand()%100 ;
                   if (odds < 70) {
                      //steals
                      b.setCurPlayer(this) ;
                      f.setBall(i,j,false) ;
                      f.setBall(cox,coy,true) ;
                      b.setPrePlayer(cp) ;
                      std::cout << "Success! " ;
                      }
                   else {
                      odds = rand()%100 ;
                      std::cout << "Failure... " ;
                      if (odds < 20 ) {
                         if (y_flag == true) {
                            // remove player from simulation
                            std::cout << "Get out !" ;
                         }
                         else {
                            y_flag = true ;
                            std::cout << "Yellow Card!" ;
                         }
                      }
                   }
                   }
                }
    }
    }
    }
    }
    std::cout << std::endl ;
}


void Attacker::special_move(Ball& b,Field& f) {
    std::cout << "Attacker's special move!" << std::endl ;
    int m ;
     Player  *cp = b.getCurPlayer() ;
     if(cp != nullptr) {
      if (pteam == cp->getPTeam()) {
        for (int i=cox-1 ; i<=cox+1 ; i+=2) {
            if(i >= 0 && i < 8) {
            for(int j=coy-1 ; j<=coy+1 ; j++) {
                /*ευρεση αντιπαλου παικτη κοντα σε μενα */
                 int d = coy - j ; // distance from opponent negative=left, positive=right
                 if (d==0) {               // opponent in the same column ?
                    m = coy + 4*rand()%2 - 2 ; // move either left or right
                }
                else{                    // opponent not in the same column (left or right)
                    m = coy + 2*d ;    //
                }
                 switch (m) {
                    case -2 :             // out of bounds far left side
                      coy = -m ;      // move to opposite direction
                      break;
                    case -1 :
                      if (d == 0) {
                        coy = coy + 2 ;
                      }
                      else{
                        coy = coy - 1 ;
                      }
                      break;
                    case 8 + 1 :
                      coy = coy - 2 ;
                      break;
                    case 8:
                      coy = coy + 1 ;
                      break ;
                    default:
                      coy = m ;
                }
            } // end for j
            }
        } // end for i
      }
     }

}
               /* switch (m) {
                    case -2 :             // out of bounds far left side
                      cord[1] = -m ;      // move to opposite direction
                      break;
                    case -1 :
                      if (d == 0) {
                        cord[1] = cord[1] + 2 ;
                      }
                      else{
                        cord[1] = cord[1] - 1 ;
                      }
                      break;
                    case 9 :
                      cord[1] = cord[1] - 2 ;
                      break;
                    case 8:
                      cord[1] = cord[1] + 1 ;
                      break ;
                    default:
                      cord[1] = m ;
                }*/
            //}
        //}
    //}
//}

Attacker::Attacker(std::string s) : Player(s) {}
Defender::Defender(std::string s) : Player(s) {}
