#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "team.h"
class Ball  ;
class Field ;
class Player
{
    protected:
    int cox;
    int coy; //coordinates
    std::string name;
    int number;
    int move_l; //moving line
    int forw_l; //forwording line
    std::string pteam ;
    public:
    Player() ;
    Player(const std::string&) ;
    ~Player();
    void move(Field&,Ball&);
    void transfer(Ball&,Field&) ;
    void setPName(const std::string&) ;
    void setPTeam(const std::string&) ;
    void setCoordx(int) ;
    void setCoordy(int) ;
    std::string getPName() ;
    void setPNumber(int) ;
    int getPNumber() ;
    void setMLine(int) ;
    int getMLine() ;
    void setFLine(int) ;
    int getFLine() ;
    int getCoordx();
    int getCoordy();
    std::string getPTeam() ;
    virtual void special_move() = 0 ;
    virtual void special_move(Ball&,Field&) = 0 ;
};


class Defender : public Player{
    public:
        Defender();
        Defender(std::string);
        ~Defender();
        int steals ;
        void special_move() {} ;
        void special_move(Ball&,Field&);
    protected:
        bool y_flag; //yellow flags

};


class Attacker : public Player{
    public:
        Attacker();
        Attacker(std::string) ;
        ~Attacker() ;
        void special_move() {} ;
        void special_move(Ball&,Field&);
};

#endif // PLAYER_H
