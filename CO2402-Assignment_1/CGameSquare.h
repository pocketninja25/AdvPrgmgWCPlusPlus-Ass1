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
	//Constructor
	CGameSquare(string iSquareName, ESquareCategory iSquareType);
	
	//Destructor
	virtual ~CGameSquare();

	//Passes over event function
	virtual string OnPassOver(CPlayer* pPassingPlayer) = 0;

	//Lands on event function
	virtual string OnLand(CPlayer* pLandingPlayer) = 0;

	//Returns the name of this square
	string GetName();

	//Returns the type of this square
	ESquareCategory GetType();
};

#endif