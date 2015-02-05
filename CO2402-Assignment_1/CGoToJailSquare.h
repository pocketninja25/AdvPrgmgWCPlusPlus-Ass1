#ifndef CGOTOJAILSQUARE_H
#define CGOTOJAILSQUARE_H

#include "CGameSquare.h"

//Type 7 Square

class CGoToJailSquare : public CGameSquare
{
private:

public:
	CGoToJailSquare(string iSquareName);

	virtual ~CGoToJailSquare();

	string OnPassOver(CPlayer* pPassingPlayer);

	string OnLand(CPlayer* pLandingPlayer);

};

#endif