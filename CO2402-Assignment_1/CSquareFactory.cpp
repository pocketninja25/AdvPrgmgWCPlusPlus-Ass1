#include "CSquareFactory.h"

#ifdef _DEBUG
#define DEBUG_NEW_PLACEMENT (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW_PLACEMENT
#endif

CSquareFactory::CSquareFactory()
{
	//Nothing to construct
}

CSquareFactory::~CSquareFactory()
{
	//Nothing to destruct
}

void CSquareFactory::LoadSquares(string fileName, vector<CGameSquare*>* piList)
{
	mpSquareList = piList;						//Point member list to passed list
	mInStream.open(fileName);					//Load the game file name
	int readValue = -1;							//The value read in from file
	ESquareCategory category = CATEGORY_GO;		//The category converted from file read
	CGameSquare* pCreatedSquare = 0;			//Pointer to the square created

	while (mInStream && mInStream >> readValue)	//Read in from the file
	{
		category = (ESquareCategory)(readValue - 1);	//Convert the read number from the file to its square category enumeration

		switch (category)	//Create the correct subclass of CGameSquare by calling its respective creation function
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
		//Push the newly created square onto the square list
		mpSquareList->push_back(pCreatedSquare);
	}
}

CGameSquare* CSquareFactory::CreateProperty()
{
	string inString = "";		//Input string
	string name = "";			//Name of the square

	//Capture property name
	mInStream >> inString;
	name += inString + " ";
	mInStream >> inString;
	name += inString;

	//Capture property purchase cost
	int cost = 0;
	mInStream >> cost;

	//Capture property rent
	int rent = 0;
	mInStream >> rent;

	//Capture and convert property colour group
	int group = 0;
	EPropertyGroup colourGroup = (EPropertyGroup)0;
	mInStream >> group;
	colourGroup = (EPropertyGroup) group;

	//Create new property based on read values
	CPropertySquare* pNewProperty = new DEBUG_NEW_PLACEMENT CPropertySquare(name, colourGroup, cost, rent);

	//Associate property with other properties of the same colour group that are already in the list
	AssociateProperty(pNewProperty);

	//Return the property
	return pNewProperty;

}

CGameSquare* CSquareFactory::CreateGo()
{
	//Create and return the go tile
	return new DEBUG_NEW_PLACEMENT CGoSquare(GetName());
}

CGameSquare* CSquareFactory::CreateRetailPark()
{
	//Create a new retail park (is same as a property but with predetermined values)
	CPropertySquare* pNewPark = new DEBUG_NEW_PLACEMENT CPropertySquare(GetName(), GROUP_RETAILPARK, 200, 10);

	//Associate property with other properties of the same colour group that are already on the list
	AssociateProperty(pNewPark);

	//Return the property
	return pNewPark;
}

CGameSquare* CSquareFactory::CreateBonus()
{
	//Create and return a new bonus square
	return new DEBUG_NEW_PLACEMENT CBonusSquare(GetName());
}

CGameSquare* CSquareFactory::CreatePenalty()
{
	//Create and return a new penalty square
	return new DEBUG_NEW_PLACEMENT CPenaltySquare(GetName());
}

CGameSquare* CSquareFactory::CreateJail()
{
	//Create and return a new jail square
	return new DEBUG_NEW_PLACEMENT CJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateGoToJail()
{
	//Create and return a new Go to jail square
	return new DEBUG_NEW_PLACEMENT CGoToJailSquare(GetName());
}

CGameSquare* CSquareFactory::CreateFreeParking()
{
	//Create and return a new free parking square
	return new DEBUG_NEW_PLACEMENT CFreeParkingSquare(GetName());
}

string CSquareFactory::GetName()
{
	//Capture a name from file - only works if the name is the rest of the current line - will not work for properties as their name is followed by values
	string name = "";
	mInStream.get();	//Eliminates the leading space character
	getline(mInStream, name);	//Capture the square's name
	return name;
}

void CSquareFactory::AssociateProperty(CPropertySquare* piNewProp)
{
	//Make colour groups aware of group members - this means adding a vector of property pointers to properties and filling them with shared group members here - this means that when they calculate rent they can double if a single player owns all three
	for (unsigned int i = 0; i < mpSquareList->size(); i++)	//Search for properties of the same colour group
	{
		CGameSquare* pCurrentSquare = mpSquareList->at(i);
		if (pCurrentSquare->GetType() == CATEGORY_PROPERTY)	//The current square is a property square - need this as pCurrentSquare is a generalised pointer - not neccesarily a property
		{
			CPropertySquare* pOtherProperty = static_cast<CPropertySquare*>(pCurrentSquare);	//Cast found property to a property pointer
			
			if (pOtherProperty->GetPropertyGroup() == piNewProp->GetPropertyGroup())	//If in the same group
			{
				//Associate group members
				pOtherProperty->AddGroupMember(piNewProp);
				piNewProp->AddGroupMember(pOtherProperty);
			}
		}
	}
}