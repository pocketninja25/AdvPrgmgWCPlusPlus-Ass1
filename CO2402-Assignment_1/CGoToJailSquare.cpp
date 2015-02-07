#include "CGoToJailSquare.h"
#include <sstream>

CGoToJailSquare::CGoToJailSquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_GOTOJAIL)
{
	//No additional construction
}

CGoToJailSquare::~CGoToJailSquare()
{
	//Nothing to destruct
}

string CGoToJailSquare::OnPassOver(CPlayer* pPassingPlayer)
{
	//Nothing Happens - Return blank string
	return "";
}

string CGoToJailSquare::OnLand(CPlayer* pLandingPlayer)
{
	stringstream out;

	//Send player to jail
	out << pLandingPlayer->GetName() << " goes to Jail" << endl;
	pLandingPlayer->SetJailState(true);
	
	return out.str();
}