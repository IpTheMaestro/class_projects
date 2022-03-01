//Hanoi.cpp -- Game base-class methods definitions
#include "Hanoi.h"
#include <iostream>

using namespace std;

Player::Player(const string & fn, int m, int g, int s, double t, double totT,  
        double aveM, double aveT) : name(fn), moves(m), games(g),
        time(t), totalTime(totT), aveMoves(aveM), aveTime(aveT) {}
    
void Player::setName(string n) { name = n; };
string Player::getName() const { return name; };
int Player::getMoves() const { return moves; };
int Player::getGames() const { return games; };
void Player::setTime(double t) { time = t; };
double Player::getTime() const { return time; };
double Player::getAveMoves() const { return aveMoves; };
double Player::getAveTime() const { return aveTime; };

void Player::addMoves(int m) {
    moves += m;
};
void Player::addGames(int g) { 
    games += 1;
    calAveMoves();
}
void Player::addTime(double t){ 
    totalTime += t; 
    calAveTime();
    };

void Player::show() const{
    cout << "<<<<< Here are your results, " << name << endl << endl;
    cout << "* Number of moves used: " << moves << endl;
    cout << "* Final time taken: " << time << " seconds." << endl;
    cout << "* Number of games played: " << games << endl;
    cout.precision(4);
    cout << "* Average moves per game: " << aveMoves << endl;
    cout << "* Average time taken per game: " << aveTime << " seconds." << endl << endl;
}