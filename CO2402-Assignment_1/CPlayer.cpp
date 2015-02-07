#include "CPlayer.h"

CPlayer::CPlayer(EPlayerPieces iPiece)
{
	mPiece = iPiece;
	mBalance = 1500;
	mInJail = false;
	mBoardPos = 0;
}

CPlayer::~CPlayer()
{

}

unsigned int CPlayer::GetBoardPosition()
{
	return mBoardPos;
}

void CPlayer::SetBoardPosition(unsigned int newPos)
{
	mBoardPos = newPos;
}

string CPlayer::GetName()
{
	return gPIECE_NAMES[mPiece];
}

void CPlayer::GiveCash(int amount)
{
	mBalance += amount;
}

void CPlayer::TakeCash(int amount)
{
	mBalance -= amount;
}

int CPlayer::GetBalance()
{
	return mBalance;
}

bool CPlayer::IsInJail()
{
	return mInJail;
}

void CPlayer::SetJailState(bool newJailState)
{
	mInJail = newJailState;
}

void CPlayer::BecomeOwner(CPropertySquare* pNewProperty)
{	
	mOwnedProperties.push_back(pNewProperty);
}