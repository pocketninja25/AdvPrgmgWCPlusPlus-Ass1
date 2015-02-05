#ifndef CRETAILPARKSQUARE_H
#define CRETAILPARKSQUARE_H

#include "CPropertySquare.h"

//Type 3 Square

class CRetailParkSquare : public CPropertySquare
{
private:
	
public:
	CRetailParkSquare(string iSquareName);

	virtual ~CRetailParkSquare();

	//May need to force overload - not sure
	//string OnPassOver(CPlayer* passingPlayer);

	//string OnLand(CPlayer* landingPlayer);
};

#endif