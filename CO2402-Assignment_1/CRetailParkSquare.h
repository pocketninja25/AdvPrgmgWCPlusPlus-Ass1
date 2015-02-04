#ifndef CRETAILPARKSQUARE_H
#define CRETAILPARKSQUARE_H

#include "CGameSquare.h"

//Type 3 Square

class CRetailParkSquare : public CGameSquare
{
private:

public:
	CRetailParkSquare(string iSquareName);

	virtual ~CRetailParkSquare();

	void OnPassOver(CPlayer* passingPlayer);

	void OnLand(CPlayer* landingPlayer);
};

#endif