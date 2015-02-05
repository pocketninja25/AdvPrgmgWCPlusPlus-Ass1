#ifndef CPENALTYSQUARE_H
#define CPENALTYSQUARE_H

#include "CGameSquare.h"

//Type 5 Square

class CPenaltySquare : public CGameSquare
{
private:

public:
	CPenaltySquare(string iSquareName);

	virtual ~CPenaltySquare();

	string OnPassOver(CPlayer* passingPlayer);

	string OnLand(CPlayer* landingPlayer);

};

#endif