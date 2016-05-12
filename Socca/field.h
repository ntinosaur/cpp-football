#ifndef FIELD_H
#define FIELD_H

#include "player.h"

class Field
{
	bool ball[10][8];
	Player *fplayer[10][8];
public:
    Field();
    ~Field();
    Player *getFPlayer(int,int) ;
    void setFPlayer(int,int,Player*) ;
    void setBall(int,int,bool) ;
    bool isBall(int,int) ;
    void print_f(Team*,Team*,Ball*);
};

#endif // FIELD_H




/*Field bernabeu ;

for(int i = cox - 1 ; i <= cox + 1 ; i+=2) {
	for(int j = coy - 1 ; j <= coy + 1 ; j++){
		Player *fp = bernabeu.getFPlayer(i,j) ;
		if (fp != nullptr) { // is there a player ?
			if (pteam != fp->getPTeam()) { // is he his opponent ?


			}

		}


	}
}*/
