#include "CPlayer.h"

CPlayer::CPlayer(EPlayerPieces iPiece)	//Constructor
{
	mPiece = iPiece;	//Set player piece
	mBalance = 1500;	//Initialise starting cash
	mInJail = false;	//Not in jail at start of game
	mBoardPos = 0;		//Start on the board at position 0
}

CPlayer::~CPlayer()
{
	//Nothing to destruct
}

unsigned int CPlayer::GetBoardPosition()	//Getter for mBoardPos
{
	return mBoardPos;
}

void CPlayer::SetBoardPosition(unsigned int newPos)	//Setter for mBoardPos
{
	mBoardPos = newPos;
}

string CPlayer::GetName()			//Gets the name of the players piece - from gPIECE_NAMES array using mPiece as index
{
	return gPIECE_NAMES[mPiece];
}

void CPlayer::GiveCash(int amount)	//Adds 'amount' to players cash total
{
	mBalance += amount;
}

void CPlayer::TakeCash(int amount)	//Subtracts 'amount' from players cash total
{
	mBalance -= amount;
}

int CPlayer::GetBalance()			//Getter for mBalance
{
	return mBalance;
}

bool CPlayer::IsInJail()			//Getter for mInJail
{
	return mInJail;
}

void CPlayer::SetJailState(bool newJailState)	//Setter for mInJail
{
	mInJail = newJailState;
}

void CPlayer::BecomeOwner(CPropertySquare* pNewProperty)	//Adds pNewProperty to a list of properties that this player owns
{	
	mOwnedProperties.push_back(pNewProperty);
}