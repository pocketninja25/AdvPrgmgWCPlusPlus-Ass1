#ifndef CPLAYER_H
#define CPLAYER_H

#include "Constants.h"
//Players do not go bankrupt - balance can be negative

class CPlayer
{
private:
	EPlayerPieces mPiece;
	int mBalance;
	bool mInJail;
	unsigned int mBoardPos;

public:
	CPlayer(EPlayerPieces iPiece);
	~CPlayer();

	unsigned int GetBoardPosition();
	void SetBoardPosition(unsigned int newPos);

	string GetName();

	bool PurchaseProperty();	//Return whether the purchase was successful - and perform the purchase action

	void GiveCash(int amount);

	void TakeCash(int amount);

	int GetBalance();
	//Call the passes over event not for the starting space, but each subsequent space - not including the landing on space

	//Roll Dice Function - Here or maybe in monopoly class
};

#endif