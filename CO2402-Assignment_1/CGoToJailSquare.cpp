#include "CGoToJailSquare.h"

CGoToJailSquare::CGoToJailSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CGoToJailSquare::~CGoToJailSquare()
{
	//Nothing to destruct
}

void CGoToJailSquare::OnPassOver(CPlayer* passingPlayer)
{
	//Nothing Happens
}

void CGoToJailSquare::OnLand(CPlayer* landingPlayer)
{
	//Output 
	/*On Land - 
	//'<Player> lands on Go to Jail'
	//Put player in jail, (and call jail->OnLand())
	*/
}