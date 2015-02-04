#include "CFreeParkingSquare.h"

CFreeParkingSquare::CFreeParkingSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CFreeParkingSquare::~CFreeParkingSquare()
{
	//Nothing to destruct
}

void CFreeParkingSquare::OnPassOver(CPlayer* passingPlayer)
{
	//Do Nothing
}

void CFreeParkingSquare::OnLand(CPlayer* landingPlayer)
{
	//On land - Output 
	/* '<Player>lands on Free Parking'
	'<Player> is resting'
	*/
}