#include "CGoSquare.h"

CGoSquare::CGoSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CGoSquare::~CGoSquare()
{
	//Nothing to destruct
}

void CGoSquare::OnPassOver(CPlayer* passingPlayer)
{
	//On passover - player collects 200£
	//-'<Player> passes GO and collects £200'}
}

void CGoSquare::OnLand(CPlayer* landingPlayer)
{
	//On land - '<Player> lands on GO'
	//- player collects 200£ (check if an output)
}