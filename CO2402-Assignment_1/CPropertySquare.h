#ifndef CPROPERTYSQUARE_H
#define CPROPERTYSQUARE_H

#include "CGameSquare.h"

//Type 1 Square

//Colour groups - Brown, light green, red, blue, green, light blue, yellow, purple & two airports

class CPropertySquare : public CGameSquare
{
private:
	//Colour group - (of which there are 6) - enum?
	//Cost - int
	//Rent - int

public:
	CPropertySquare(string iSquareName);

	virtual ~CPropertySquare();

	void OnPassOver(CPlayer* passingPlayer);

	void OnLand(CPlayer* landingPlayer);
};

#endif