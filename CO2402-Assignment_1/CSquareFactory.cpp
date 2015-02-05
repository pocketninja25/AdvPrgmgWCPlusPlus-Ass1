#include "CSquareFactory.h"

CSquareFactory::CSquareFactory()
{

}

CSquareFactory::~CSquareFactory()
{

}

void CSquareFactory::LoadSquares(string fileName, vector<CGameSquare*>* piList)
{
	mpGameBoard = piList;
	mInStream.open(fileName);
	int readValue;
	ESquareCategory category;
	CGameSquare* pCreatedSquare;

	while (mInStream && mInStream >> readValue)
	{
		category = (ESquareCategory)(readValue - 1);
		switch (category)
		{
		case CATEGORY_PROPERTY:
			pCreatedSquare = CreateProperty();
			break;
		case CATEGORY_GO:
			pCreatedSquare = CreateGo();
			break;
		case CATEGORY_RETAILPARK:
			pCreatedSquare = CreateRetailPark();
			break;
		case CATEGORY_BONUS:
			pCreatedSquare = CreateBonus();
			break;
		case CATEGORY_PENALTY:
			pCreatedSquare = CreatePenalty();
			break;
		case CATEGORY_JAIL:
			pCreatedSquare = CreateJail();
			break;
		case CATEGORY_GOTOJAIL:
			pCreatedSquare = CreateGoToJail();
			break;
		case CATEGORY_FREEPARKING:
			pCreatedSquare = CreateFreeParking();
			break;
		default:
			//ERROR
			break;
		}
		mpGameBoard->push_back(pCreatedSquare);
	}
}

CGameSquare* CSquareFactory::CreateProperty()
{
	string inString;
	string name;
	//Capture property name
	mInStream >> inString;
	name += inString + " ";
	mInStream >> inString;
	name += inString;

	int cost;
	mInStream >> cost;

	int rent;
	mInStream >> rent;

	int group;
	EPropertyGroup colourGroup;
	mInStream >> group;
	colourGroup = (EPropertyGroup) group;

	return new CPropertySquare(name, colourGroup, cost, rent);

}

CGameSquare* CSquareFactory::CreateGo()
{
	return new CGoSquare(GetName());
}

CGameSquare* CSquareFactory::CreateRetailPark()
{
	return new CRetailParkSquare(GetName());
}

CGameSquare* CSquareFactory::CreateBonus()
{
	return new CBonusSquare(GetName());
}

CGameSquare* CSquareFactory::CreatePenalty()
{
	return new CPenaltySquare(GetName());
}

CGameSquare* CSquareFactory::CreateJail()
{
	return new CJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateGoToJail()
{
	return new CGoToJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateFreeParking()
{
	return new CFreeParkingSquare(GetName());
}

string CSquareFactory::GetName()
{
	string name;
	mInStream.get();
	getline(mInStream, name);
	return name;
}