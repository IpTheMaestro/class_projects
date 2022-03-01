// Hanoi.h -- Program base class 
#ifndef HANOI_H_
#define HANOI_H_
#include <string>
using std::string;

// Player class with attributes and prototypes.
class Player
{
private:
    string name;
    int moves;
    int games;
    double time;
    double totalTime;
    double aveMoves;
    double aveTime;
    void calAveMoves() { aveMoves = double(moves)/games; };
    void calAveTime() { aveTime = totalTime/games; };

public:
    Player (const string & fn = "Unknown Player", int m = 0, int g = 0, int s = 0,
                double t = 0, double totT = 0.0, double aveM = 0.0, double aveTime = 0.0);
    void setName(string n);
    string getName() const;
    int getMoves() const;
    int getGames() const;
    void setTime(double t);
    double getTime() const;
    double getAveMoves() const;
    double getAveTime() const;
    void addMoves(int m);
    void addTime(double t);
    void addGames(int g);
    void show() const;
};
#endif
