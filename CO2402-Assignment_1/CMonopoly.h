#ifndef CMONOPOLY_H
#define CMONOPOLY_H

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include "CSquareFactory.h"
#include "Random.h"

//Monopoly is a singleton - there will only be one - it is the manager class

class CMonopoly
{
private:
	CSquareFactory mSquareCreation;
	vector<CGameSquare*> mGameBoard;

	vector<CPlayer*> mPlayers;

	unsigned int mTurnNo;

public:
	CMonopoly();

	~CMonopoly();

	void OutputBoard();

	void TakeTurn();

	void PlayTurns(unsigned int noTurns);

};

#endif