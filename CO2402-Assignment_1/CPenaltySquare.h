#ifndef CPENALTYSQUARE_H
#define CPENALTYSQUARE_H

#include "CGameSquare.h"
#include "Random.h"

//Type 5 Square

class CPenaltySquare : public CGameSquare
{
private:

public:
	//Constructor
	CPenaltySquare(string iSquareName);

	//Destructor
	virtual ~CPenaltySquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);

};

#endif