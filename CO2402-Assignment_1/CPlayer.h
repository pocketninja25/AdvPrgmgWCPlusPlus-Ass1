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
	EPlayerPieces mPiece;
	int mBalance;
	bool mInJail;
	unsigned int mBoardPos;
	vector<CPropertySquare*> mOwnedProperties;

public:
	CPlayer(EPlayerPieces iPiece);
	~CPlayer();

	unsigned int GetBoardPosition();
	void SetBoardPosition(unsigned int newPos);

	string GetName();

	void GiveCash(int amount);

	void TakeCash(int amount);

	int GetBalance();

	bool IsInJail();

	void SetJailState(bool newJailState);

	void BecomeOwner(CPropertySquare* pNewProperty);

};

#endif