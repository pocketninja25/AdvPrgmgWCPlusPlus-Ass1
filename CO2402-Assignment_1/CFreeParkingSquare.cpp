#include "CFreeParkingSquare.h"
#include <sstream>

CFreeParkingSquare::CFreeParkingSquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_FREEPARKING)
{
	//No additional construction
}

CFreeParkingSquare::~CFreeParkingSquare()
{
	//Nothing to destruct
}

string CFreeParkingSquare::OnPassOver(CPlayer* pPassingPlayer)
{
	//Nothing happens - return blank string
	return "";
}

string CFreeParkingSquare::OnLand(CPlayer* pLandingPlayer)
{
	//Create output stream
	stringstream out;
	
	out << pLandingPlayer->GetName() << " is resting" << endl;
	
	//Convert the output to a string and return it
	return out.str();
}