#ifndef CGAMESQUARE_H
#define CGAMESQUARE_H

#include <string>
using std::string;
using std::stringstream;
using std::endl;

#include "CPlayer.h"

//Abstract square class - defines basic event interfaces
class CGameSquare
{
private:
	string mSquareName;				//Name - String
	ESquareCategory mSquareType;	//Type of square this is - allows identification of square

public:
	CGameSquare(string iSquareName, ESquareCategory iSquareType);
	virtual ~CGameSquare();

	//Passes over event function
	virtual string OnPassOver(CPlayer* pPassingPlayer) = 0;

	//Lands on event function
	virtual string OnLand(CPlayer* pLandingPlayer) = 0;

	string GetName();

	ESquareCategory GetType();
};

#endif