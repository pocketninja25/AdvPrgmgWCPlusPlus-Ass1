#ifndef CGAMESQUARE_H
#define CGAMESQUARE_H

#include <string>
using namespace std;
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
	virtual void OnPassOver(CPlayer* passingPlayer) = 0;

		//Lands on event function
	virtual void OnLand(CPlayer* landingPlayer) = 0;

};

#endif