#include "CPenaltySquare.h"

CPenaltySquare::CPenaltySquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CPenaltySquare::~CPenaltySquare()
{
	//Nothing to destruct
}

void CPenaltySquare::OnPassOver(CPlayer* passingPlayer)
{
	//Nothing Happens
}

void CPenaltySquare::OnLand(CPlayer* landingPlayer)
{
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
}