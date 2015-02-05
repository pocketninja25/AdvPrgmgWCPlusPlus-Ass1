#include "CPlayer.h"

CPlayer::CPlayer(EPlayerPieces iPiece)
{
	mPiece = iPiece;
	mBalance = 200;
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
	return PieceNames[mPiece];
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