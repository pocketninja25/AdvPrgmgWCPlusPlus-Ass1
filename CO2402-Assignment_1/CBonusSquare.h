#ifndef CBONUSSQUARE_H
#define CBONUSSQUARE_H

#include "CGameSquare.h"

//Type 4 Square

class CBonusSquare : public CGameSquare
{
private:

public:
	CBonusSquare(string iSquareName);

	virtual ~CBonusSquare();

	void OnPassOver(CPlayer* passingPlayer);
	
	void OnLand(CPlayer* landingPlayer);

};

#endif