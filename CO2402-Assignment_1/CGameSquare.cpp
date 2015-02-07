#include "CGameSquare.h"

CGameSquare::CGameSquare(string iSquareName, ESquareCategory iCategory)
{
	//Set the name of the square
	mSquareName = iSquareName;
	mSquareType = iCategory;
}

CGameSquare::~CGameSquare()
{
	//Nothing to destruct
}

string CGameSquare::GetName()
{
	return mSquareName;
}

ESquareCategory CGameSquare::GetType()
{
	return mSquareType;
}