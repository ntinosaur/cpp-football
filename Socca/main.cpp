#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "team.h"
#include "ball.h"
#include "game.h"
#include "field.h"

using namespace std;




int main()
{
    int coi,coj,num,movl,fol ;
    string nm,tn ;

    srand(time(0)) ;
    Game game1("Manchester","Leicester") ;
    Field f1;
    Game& refgame = game1 ;
	int turns = 0 ;
	Ball * b1 = game1.getBall() ;
	Ball& bref = *b1 ;
	Team * t1 = game1.getTeam1();
	Team * t2 = game1.getTeam2();

	/*for(int i = 0 ; i < 5 ; i++){
        Player *p = t1->getPlayer(i) ;
        cout << "Team 1," << i ;
        cin >> coi >> coj >> fol ;
        p->setCoordx(coi);
        p->setCoordy(coj);
        f1.setFPlayer(coi, coj, p) ;
        p->setPNumber(9);
        p->setMLine(coi) ;
        p->setFLine(fol) ;
        p->setPName("Ken") ;
        p-> setPTeam("Manchester") ;
        cout << endl << "Team 2," << i ;
        p = t2->getPlayer(i) ;
        cin >> coi >> coj >> fol ;
        p->setCoordx(coi);
        p->setCoordy(coj);
        f1.setFPlayer(coi,coj,p) ;
        p->setPNumber(9);
        p->setMLine(coi) ;
        p->setFLine(fol) ;
        p->setPName("Ryu") ;
        p-> setPTeam("Leicester") ;
	}*/
	for(int i = 0 ; i < 5 ; i++){
        Player *p = t1->getPlayer(i) ;
        cout << "Team 1," << i ;
        //cin >> coi >> coj >> fol ;
        p->setCoordx(i*2);
        p->setCoordy(i);
        p->setPNumber(9);
        p->setMLine(i) ;
        p->setFLine(i*2+1) ;
        p->setPName("Ken") ;
        p-> setPTeam("Manchester") ;
        cout << endl << "Team 2," << i ;
        p = t2->getPlayer(i) ;
        //cin >> coi >> coj >> fol ;
        p->setCoordx(i*2+1);
        p->setCoordy(i*2);
        p->setPNumber(9);
        p->setMLine(i*2+1) ;
        p->setFLine(i*2) ;
        p->setPName("Ryu") ;
        p-> setPTeam("Leicester") ;
	}
	Player * cur = t1->getPlayer(1) ;
	int x = cur->getCoordx() ;
	int y = cur->getCoordy() ;
	f1.setBall(x,y,true) ;
    b1->setCurPlayer(cur) ;
	char fak ;
	while( turns < 50 && fak !='e' && (t1->getTgoals()<7 || t2->getTgoals() <7)) {
	  cout <<"Turn " << turns+1 << endl ;


	  refgame.runTurn(f1) ;
	  b1->rearrange(&f1) ;
	  turns++ ;

	  //print stadium
	  cout << "  - - - - - - - - " << endl ;
      f1.print_f(t1,t2,b1) ;
      cout << "  - - - - - - - - " << endl ;// end i for


	  cin >> fak ;
	}

    return 0;
}
