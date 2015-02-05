#include "CPropertySquare.h"
#include <sstream>
CPropertySquare::CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent) : CGameSquare(iSquareName)
{
	mGroup = iGroup;
	mPurchaseCost = iPurchaseCost;
	mRent = iRent;
}

CPropertySquare::~CPropertySquare()
{
	//Nothing to destruct
}

string CPropertySquare::OnPassOver(CPlayer* passingPlayer)	
{
	//Nothing Happens
	return "";
}

string CPropertySquare::OnLand(CPlayer* landingPlayer)	
{
	stringstream out;
	
	
	return "";
}