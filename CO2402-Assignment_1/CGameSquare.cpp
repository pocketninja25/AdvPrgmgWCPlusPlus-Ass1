#include "CGameSquare.h"

CGameSquare::CGameSquare(string iSquareName)
{
	mSquareName = iSquareName;
}

CGameSquare::~CGameSquare()
{

}

string CGameSquare::GetName()
{
	return mSquareName;
}