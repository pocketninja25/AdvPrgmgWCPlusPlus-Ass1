#include "CJailSquare.h"

CJailSquare::CJailSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CJailSquare::~CJailSquare()
{
	//Nothing to destruct
}

void CJailSquare::OnPassOver(CPlayer* passingPlayer)
{
	//Nothing Happens
}

void CJailSquare::OnLand(CPlayer* landingPlayer)
{
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
}