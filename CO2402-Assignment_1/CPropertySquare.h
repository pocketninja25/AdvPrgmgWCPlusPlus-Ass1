#ifndef CPROPERTYSQUARE_H
#define CPROPERTYSQUARE_H

#include "CGameSquare.h"

//Type 1 Square

class CPropertySquare : public CGameSquare
{
private:
	EPropertyGroup mGroup;
	int mPurchaseCost;
	int mRent;

public:
	CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent);

	virtual ~CPropertySquare();

	string OnPassOver(CPlayer* passingPlayer);

	string OnLand(CPlayer* landingPlayer);
};

#endif