#include "CGoSquare.h"
#include <sstream>

CGoSquare::CGoSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CGoSquare::~CGoSquare()
{
	//Nothing to destruct
}

string CGoSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//On passover - player collects 200£
	return "";
	//-'<Player> passes GO and collects £200'}
}

string CGoSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	stringstream out;
	//On land - '<Player> lands on GO'
	//- player collects 200£ (check if an output)
	return out.str();
}