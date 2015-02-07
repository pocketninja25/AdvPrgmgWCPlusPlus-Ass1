#ifndef CGOSQUARE_H
#define CGOSQUARE_H

#include "CGameSquare.h"

//Type 2 Square

class CGoSquare : public CGameSquare
{
private:

public:
	CGoSquare(string iSquareName);

	virtual ~CGoSquare();

	string OnPassOver(CPlayer* pPassingPlayer);

	string OnLand(CPlayer* pLandingPlayer);

};

#endif