#include "CPenaltySquare.h"
#include <sstream>

CPenaltySquare::CPenaltySquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CPenaltySquare::~CPenaltySquare()
{
	//Nothing to destruct
}

string CPenaltySquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens
	return "";
}

string CPenaltySquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	stringstream out;
	//On Land -	Random event - 
	//Pay food bill. Player loses £20.
	//Pay phone bill. Player loses £50
	//Pay heating bill. Player loses £100.
	//Pay vehicle tax. Player loses £150.
	//Pay fuel bill. Player loses £200
	//Pay windfall tax. Player loses £300

	//oUTPUT 
		//'<Player> lands on Penalty'
		//'Pay food bill. Player loses £20' <<THIS IS THE SPECIFIC EVENT>>
		//'<Player> has <current balance>'
	return out.str();
}