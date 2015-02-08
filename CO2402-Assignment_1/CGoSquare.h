#ifndef CGOSQUARE_H
#define CGOSQUARE_H

#include "CGameSquare.h"

//Type 2 Square

class CGoSquare : public CGameSquare
{
private:

public:
	//Constructor
	CGoSquare(string iSquareName);

	//Destructor
	virtual ~CGoSquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);

};

#endif