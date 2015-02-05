#include "CFreeParkingSquare.h"
#include <sstream>

CFreeParkingSquare::CFreeParkingSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CFreeParkingSquare::~CFreeParkingSquare()
{
	//Nothing to destruct
}

string CFreeParkingSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Do Nothing
	return "";
}

string CFreeParkingSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	stringstream out;
	
	//On land - Output 
	/* '<Player>lands on Free Parking'
	'<Player> is resting'
	*/
	
	return out.str();
}