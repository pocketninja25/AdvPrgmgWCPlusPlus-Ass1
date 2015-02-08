#ifndef CPLAYER_H
#define CPLAYER_H

#include <vector>
using std::vector;

#include "Constants.h"

//Players do not go bankrupt - balance can be negative

class CPropertySquare;

class CPlayer
{
private:
	EPlayerPieces mPiece;						//The player piece
	int mBalance;								//The players current cash balance
	bool mInJail;								//Whether or not the player is in jail
	unsigned int mBoardPos;						//The players current board position
	vector<CPropertySquare*> mOwnedProperties;	//A list of properties that the player owns

public:
	CPlayer(EPlayerPieces iPiece);				//Constructor
	~CPlayer();									//Destructor

	unsigned int GetBoardPosition();			//Returns the players current board position
	void SetBoardPosition(unsigned int newPos);	//Sets the players board position to the provided value

	string GetName();							//Returns the 'name' of the player - based on its player piece

	void GiveCash(int amount);					//Give the player 'amount' of cash - adds to players balance

	void TakeCash(int amount);					//Take 'amount' of cash from player - subtracts from players balance

	int GetBalance();							//Returns the players current balance

	bool IsInJail();							//Returns whether or not the player is in jail

	void SetJailState(bool newJailState);		//Changes players 'mInJail' value to that of 'newJailState'

	void BecomeOwner(CPropertySquare* pNewProperty);	//Adds property to players 'mOwnedProperties' list

};

#endif