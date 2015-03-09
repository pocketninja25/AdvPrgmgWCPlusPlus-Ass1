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
	static CMonopoly* mpInstance;		//The instance of this class - used to test new instance

	CSquareFactory mSquareCreation;		//Factory class to generate new game board squares - from file
	vector<CGameSquare*> mGameBoard;	//List of game board pieces, in order of board position

	vector<CPlayer*> mPlayers;			//List of players - in playing order

	unsigned int mTurnNo;				//Current turn number

	CMonopoly(int noPlayers);			//Constructor is private - can only be called by this class itself
	CMonopoly(CMonopoly const&);		//Override default constructor - do not implement
	void operator=(CMonopoly const&);	//Override = operator - do not implement

	int GetSeed(string fileName);		//Read a value for the seed from the provided file

public:
	//Returns a new (or the existing pointer to the singleton) - if a new instance is being created returns true in newInst
	static CMonopoly* GetInstance(int noPlayers = 2);

	//Destructor
	~CMonopoly();

	//Outputs the name of each board piece
	void OutputBoard();

	//Performs a single game turn
	void PlayRound();

	//Performs 'noTurns' rounds by calling Playround 'noTurns' times
	void PlayNoRounds(unsigned int noTurns);

	void OutputStats();

};

#endif