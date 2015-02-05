#ifndef CFREEPARKINGSQUARE_H
#define CFREEPARKINGSQUARE_H

#include "CGameSquare.h"

//Type 8 Square

class CFreeParkingSquare : public CGameSquare
{
private:

public:
	CFreeParkingSquare(string iSquareName);

	virtual ~CFreeParkingSquare();

	string OnPassOver(CPlayer* pPassingPlayer);

	string OnLand(CPlayer* pLandingPlayer);


	
};

#endif