#ifndef CFREEPARKINGSQUARE_H
#define CFREEPARKINGSQUARE_H

#include "CGameSquare.h"

//Type 8 Square

class CFreeParkingSquare : public CGameSquare
{
private:

public:
	//Constructor
	CFreeParkingSquare(string iSquareName);

	//Destructor
	virtual ~CFreeParkingSquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);


	
};

#endif