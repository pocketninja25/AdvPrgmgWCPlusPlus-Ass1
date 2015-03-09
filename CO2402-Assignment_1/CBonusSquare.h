#ifndef CBONUSSQUARE_H
#define CBONUSSQUARE_H

#include "CGameSquare.h"

//Type 4 Square

class CBonusSquare : public CGameSquare
{
private:
	//No private Data/Functions

public:
	//Constructor - Supply name to parent class
	CBonusSquare(string iSquareName);

	//Destructor - marked as virtual for reference 
	virtual ~CBonusSquare();

	//When a piece passes over this square
	string OnPassOver(CPlayer* pPassingPlayer);
	
	//When a piece lands on this square
	string OnLand(CPlayer* pLandingPlayer);

};

#endif