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

	void OnPassOver(CPlayer* passingPlayer);

	void OnLand(CPlayer* landingPlayer);

};

#endif