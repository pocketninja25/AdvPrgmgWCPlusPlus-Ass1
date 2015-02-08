#ifndef CJAILSQUARE_H
#define CJAILSQUARE_H

#include "CGameSquare.h"

//Type 6 Square

class CJailSquare : public CGameSquare
{
private:

public:
	//Constructor
	CJailSquare(string iSquareName);

	//Destructor
	virtual ~CJailSquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);
	
};

#endif