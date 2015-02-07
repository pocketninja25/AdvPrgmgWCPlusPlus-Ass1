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
	static CMonopoly* mpInstance;	//The instance of this class

	CSquareFactory mSquareCreation;
	vector<CGameSquare*> mGameBoard;

	vector<CPlayer*> mPlayers;

	unsigned int mTurnNo;

	CMonopoly(int noPlayers);			//Constructor is private - can only be called by this class itself
	CMonopoly(CMonopoly const&);		//Override default constructor - do not implement
	void operator=(CMonopoly const&);	//Override = operator - do not implement
public:
	//Returns a new (or the existing pointer to the singleton) - if a new instance is being created returns true in newInst
	static CMonopoly* GetInstance(int noPlayers = 2);

	//Prevent copies being made

	~CMonopoly();

	void OutputBoard();

	void PlayRound();

	void PlayNoRounds(unsigned int noTurns);

};

#endif