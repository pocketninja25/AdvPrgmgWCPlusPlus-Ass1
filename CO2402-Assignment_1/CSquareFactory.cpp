#include "CSquareFactory.h"

#ifdef _DEBUG
#define DEBUG_NEW_PLACEMENT (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW_PLACEMENT
#endif

CSquareFactory::CSquareFactory()
{

}

CSquareFactory::~CSquareFactory()
{

}

void CSquareFactory::LoadSquares(string fileName, vector<CGameSquare*>* piList)
{
	mpSquareList = piList;
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
		mpSquareList->push_back(pCreatedSquare);
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

	CPropertySquare* pNewProperty = new DEBUG_NEW_PLACEMENT CPropertySquare(name, colourGroup, cost, rent);

	AssociateProperty(pNewProperty);

	return pNewProperty;

}

CGameSquare* CSquareFactory::CreateGo()
{
	return new DEBUG_NEW_PLACEMENT CGoSquare(GetName());
}

CGameSquare* CSquareFactory::CreateRetailPark()
{
	CPropertySquare* pNewPark = new DEBUG_NEW_PLACEMENT CPropertySquare(GetName(), GROUP_RETAILPARK, 200, 10);

	AssociateProperty(pNewPark);

	return pNewPark;
}

CGameSquare* CSquareFactory::CreateBonus()
{
	return new DEBUG_NEW_PLACEMENT CBonusSquare(GetName());
}

CGameSquare* CSquareFactory::CreatePenalty()
{
	return new DEBUG_NEW_PLACEMENT CPenaltySquare(GetName());
}

CGameSquare* CSquareFactory::CreateJail()
{
	return new DEBUG_NEW_PLACEMENT CJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateGoToJail()
{
	return new DEBUG_NEW_PLACEMENT CGoToJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateFreeParking()
{
	return new DEBUG_NEW_PLACEMENT CFreeParkingSquare(GetName());
}

string CSquareFactory::GetName()
{
	string name;
	mInStream.get();
	getline(mInStream, name);
	return name;
}

void CSquareFactory::AssociateProperty(CPropertySquare* piNewProp)
{
	//Make colour groups aware of group members - this means adding a vector of property pointers to properties and filling them with shared group members here - this means that when they calculate rent they can double if a single player owns all three
	for (unsigned int i = 0; i < mpSquareList->size(); i++)
	{
		CGameSquare* pCurrentSquare = mpSquareList->at(i);
		if (pCurrentSquare->GetType() == CATEGORY_PROPERTY)
		{
			CPropertySquare* pOtherProperty = static_cast<CPropertySquare*>(pCurrentSquare);	//Cast found property to 
			
			if (pOtherProperty->GetPropertyGroup() == piNewProp->GetPropertyGroup())	//If in the same group
			{
				//Associate group members
				pOtherProperty->AddGroupMember(piNewProp);
				piNewProp->AddGroupMember(pOtherProperty);
			}
		}
	}
}