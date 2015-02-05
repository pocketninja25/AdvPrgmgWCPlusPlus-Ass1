#ifndef CGOSQUARE_H
#define CGOSQUARE_H

#include "CGameSquare.h"

//Type 2 Square

//On pass or on land - player recieves 200£ - output this to screen - message in following format /*
		//'<Player> passes GO and collects £200' */

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