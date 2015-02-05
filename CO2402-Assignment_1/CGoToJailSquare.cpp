#include "CGoToJailSquare.h"
#include <sstream>

CGoToJailSquare::CGoToJailSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CGoToJailSquare::~CGoToJailSquare()
{
	//Nothing to destruct
}

string CGoToJailSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens
	return "";
}

string CGoToJailSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	stringstream out;
	//Output 
	/*On Land - 
	//'<Player> lands on Go to Jail'
	//Put player in jail, (and call jail->OnLand())
	*/
	return out.str();
}