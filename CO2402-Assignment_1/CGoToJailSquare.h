#ifndef CGOTOJAILSQUARE_H
#define CGOTOJAILSQUARE_H

#include "CGameSquare.h"

//Type 7 Square

class CGoToJailSquare : public CGameSquare
{
private:

public:
	//Constructor
	CGoToJailSquare(string iSquareName);

	//Destructor
	virtual ~CGoToJailSquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);

};

#endif