#include "CPropertySquare.h"

CPropertySquare::CPropertySquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CPropertySquare::~CPropertySquare()
{
	//Nothing to destruct
}

void CPropertySquare::OnPassOver(CPlayer* passingPlayer)
{
	//Nothing Happens
}

void CPropertySquare::OnLand(CPlayer* landingPlayer)
{

}