#ifndef CPENALTYSQUARE_H
#define CPENALTYSQUARE_H

#include "CGameSquare.h"
#include "Random.h"

//Type 5 Square

class CPenaltySquare : public CGameSquare
{
private:

public:
	CPenaltySquare(string iSquareName);

	virtual ~CPenaltySquare();

	string OnPassOver(CPlayer* pPassingPlayer);

	string OnLand(CPlayer* pLandingPlayer);

};

#endif