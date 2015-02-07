#include "CJailSquare.h"
#include <sstream>

CJailSquare::CJailSquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_JAIL)
{
	//No additional construction
}

CJailSquare::~CJailSquare()
{
	//Nothing to destruct
}

string CJailSquare::OnPassOver(CPlayer* pPassingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens - return blank string
	return "";
}

string CJailSquare::OnLand(CPlayer* pLandingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Create output stream
	stringstream out;

	if (pLandingPlayer->IsInJail())
	{
		//Player pays to leave jail
		out << pLandingPlayer->GetName() << " pays " << gPOUND << 50 << endl;
		pLandingPlayer->TakeCash(50);

		//Player leaves jail
		pLandingPlayer->SetJailState(false);
		out << pLandingPlayer->GetName() << " gets out of jail " << endl;
	}
	else
	{
		//Output just visiting text
		out << pLandingPlayer->GetName() << " is just visiting" << endl;
	}
	
	//Convert outStream to string and return it
	return out.str();
}