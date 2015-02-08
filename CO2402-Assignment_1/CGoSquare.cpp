#include "CGoSquare.h"
#include <sstream>

CGoSquare::CGoSquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_GO)
{
	//No additional construction
}

CGoSquare::~CGoSquare()
{
	//Nothing to destruct
}

string CGoSquare::OnPassOver(CPlayer* pPassingPlayer)
{
	//Create output stream
	stringstream out;
	
	//Output 'Pass Go' message and give player £200
	out << pPassingPlayer->GetName() << " passes GO and collects " << gPOUND << 200 << endl;
	pPassingPlayer->GiveCash(200);

	//Convert output to string and return it
	return out.str();
}

string CGoSquare::OnLand(CPlayer* pLandingPlayer)
{
	stringstream out;

	//Output collection message and give player £200
	out << pLandingPlayer->GetName() << " collects " << gPOUND << 200 << endl;
	pLandingPlayer->GiveCash(200);

	return out.str();
}