#ifndef CFREEPARKINGSQUARE_H
#define CFREEPARKINGSQUARE_H

#include "CGameSquare.h"

//Type 8 Square

class CFreeParkingSquare : CGameSquare
{
private:

public:
	CFreeParkingSquare(string iSquareName);

	virtual ~CFreeParkingSquare();

	void OnPassOver(CPlayer* pasingPlayer);

	void OnLand(CPlayer* landingPlayer);


	
};

#endif