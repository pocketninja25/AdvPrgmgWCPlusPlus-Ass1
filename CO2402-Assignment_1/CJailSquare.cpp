#include "CJailSquare.h"
#include <sstream>

CJailSquare::CJailSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CJailSquare::~CJailSquare()
{
	//Nothing to destruct
}

string CJailSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens
	return "";
}

string CJailSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	stringstream out;
	//On land - If player is 'in jail'
	//- /*'<Player> goes to Jail'
	//Take 50£ from player
	//'<Player> pays £50*/
	//put player 'not in jail'	
	//This is because the player pays to get out of jail immediately - his next turn is a normal turn
	//*/

	//Player is not 'in jail'
	//- '<Player> lands on Jail'
	//- <Player> is just visiting'
	return out.str();
}