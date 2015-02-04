#include "CBonusSquare.h"

CBonusSquare::CBonusSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CBonusSquare::~CBonusSquare()
{
	//Nothing to destruct
}

void CBonusSquare::OnPassOver(CPlayer* passingPlayer)
{
	//Nothing Happens
}

void CBonusSquare::OnLand(CPlayer* landingPlayer)
{
	//Random Event

	//On Land -	Random event - 
	//Find some money.Player gains £20.
	//Win competition.Player gains £50.
	//Tax rebate.Player gains £100.
	//Win lottery.Player gains £150.
	//Bequest.Player gains £200.
	//Birthday.Player gains £300.

	//oUTPUT 
	//'<Player> lands on Bonus’
	//'Find some money. Player gains £20' <<THIS IS THE SPECIFIC EVENT>>
	//'<Player> has <current balance>'
}