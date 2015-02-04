#ifndef CJAILSQUARE_H
#define CJAILSQUARE_H

#include "CGameSquare.h"

//Type 6 Square

class CJailSquare : public CGameSquare
{
private:

public:
	CJailSquare(string iSquareName);

	virtual ~CJailSquare();

	void OnPassOver(CPlayer* passingPlayer);

	void OnLand(CPlayer* landingPlayer);
	
};

#endif