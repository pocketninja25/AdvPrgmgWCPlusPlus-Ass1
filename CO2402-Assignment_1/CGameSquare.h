#ifndef CGAMESQUARE_H
#define CGAMESQUARE_H

#include <string>
using std::string;
using std::stringstream;
using std::endl;

//Generic Square Class (Wants to be abstract most probably)
#include "CPlayer.h"

class CGameSquare
{
private:
	//Name - String
	string mSquareName;

public:
	CGameSquare(string iSquareName);
	virtual ~CGameSquare();

	//Passes over event function
	virtual string OnPassOver(CPlayer* pPassingPlayer) = 0;

	//Lands on event function
	virtual string OnLand(CPlayer* pLandingPlayer) = 0;

	string GetName();
};

#endif