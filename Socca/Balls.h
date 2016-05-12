

class Team {
    protected:
	  Player * players[11] ;
	  char name[15] ;
	  int faults,passes,goals ;
	 public:
    void action() ;
      void setTName(char tname) { name = tname ;}
      char getTName() {return name ;}
    	bool myTeam(Player p) ;
      void setTgoals(int g) { goals = g ;}
      int  getTgoals() {return goals ;}
      void setTpasses(int pass) { passes = pass ;}
      int  getTpasses() { return passes ;}
      void setTsteals(int steal) { steals = steal ;}
      int getTsteals() { return steals ;}
    	void inc_passes() {passes++ ;}
    	void inc_faults() {faults++ ;}
    	void inc_goals() {goals++; }
      Player * getPlayer(int a) { return players[a]}
};

class Ball {
protected:
	int cord[2];
	Player cur_pl, pre_pl ; // current and previous player respectively
public:
    Player getCurPlayer() { return cur_pl ;}
    Player getPrePlayer() { return pre_pl ;}
    void   setCurPlayer(Player p) { cur_pl = p ;}
    void   setPrePlayer(Player p) { pre_pl = p ;}
    void setBCoords(int x, int y) {
      cord[0] = x ;
      cord[1] = y ;
    }
    int * getBCoords(int i) {return *cord[i] ;}

    void   rearrange(Player p) {
    	if (cur_pl == nullptr) {
    		if (t1.myTeam(cur_p)) {
	          if(t1.myTeam(pre_p)) {
	             t1.inc_passes();
              }
              else { t1.inc_faults() ;}
            }else{
	          if(t2.myTeam(pre_p)) {
	             t2.inc_passes();
              }
            else{
    	      t2.inc_faults();
            }
            }

    	}
    }

    void rearrange() {
    	if(cur_pl == nullptr) {
    		if ()
    	}
    }

};





// Πως βρισκουμε την ομαδα ενος παικτη ;
bool Team::myTeam (Player p) {
   for (Player play in players) {
   	if(p == play) {
   		return true ;
   	}
   }
   return false ;
}

// Είναι δύο παίκτες από την ίδια ομάδα
bool Team::same_team(Player p1, Player p2) {
    int c = 0 ;
    for (Player p in players) {
        if(p == p1 || p == p2) {
            c++ ;
        }
    }
    if (c == 2 || c == 0) { return true ;}  // και οι δύο ομάδα 1 ή και οι δύο ομάδα 2
    else {return false ;}
}


class Game {
protected:
	Team team,team2 ;
	Ball b1 ;
public:
	int turns ;
	void runTurn() {
		int order = rand()%2 ;
		if (order == 0) {
      team1.action() ;
      team2.action() ;
    }else{
      team2.action() ;
      team1.action() ;
    }
    }

}


void Team::action() {
  for (int i = 0; i < 11 ; i++) {
    Player p = this->getPlayer(i) ;
    act = rand()%100 ;
    if (act < 35) {
      p.move() ;
    }else if(act < 70) {
      p.transfer();
    }




    Game game1 = new Game() ;
	int turns = 0 ;
	Team * t1 = game1.getTeam1();
	Team * t2 = game1.getTeam2();
	while( turns < max_turns && (t1->getGoals()<7 || t2->getGoals() <7)) {
	  game1.runTurn() ;
	  turns++ ;Game game1 = new Game() ;
	int turns = 0 ;
	Team * t1 = game1.getTeam1();
	Team * t2 = game1.getTeam2();
	while( turns < max_turns && (t1->getGoals()<7 || t2->getGoals() <7)) {
	  game1.runTurn() ;
	  turns++ ;
	}
	}
    else{ p.special_move();}
  }
  // εδώ θα μπει η αναθεση()
}
