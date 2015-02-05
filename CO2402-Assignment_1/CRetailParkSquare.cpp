#include "CRetailParkSquare.h"
#include <sstream>

CRetailParkSquare::CRetailParkSquare(string iSquareName) : CPropertySquare(iSquareName, GROUP_RETAILPARK, 200, 10)
{
	//No additional construction
}

CRetailParkSquare::~CRetailParkSquare()
{
	//Nothing to destruct
}

//string CRetailParkSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
//{
//	//Nothing Happens
//}
//
//string CRetailParkSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
//{
//	stringstream out;
//
//	return out.str();
//}