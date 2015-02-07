#ifndef CSQUAREFACTORY_H
#define CSQUAREFACTORY_H

#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;

#include "CGameSquare.h"
#include "CPropertySquare.h"
#include "CGoSquare.h"
#include "CBonusSquare.h"
#include "CPenaltySquare.h"
#include "CJailSquare.h"
#include "CGoToJailSquare.h"
#include "CFreeParkingSquare.h"

class CSquareFactory
{
private:
	vector<CGameSquare*>* mpSquareList;
	ifstream mInStream;

	//Get the name of a square
	string GetName();

	//Create Property Function (1)
	CGameSquare* CreateProperty();

	//Create Go Square Function (2)
	CGameSquare* CreateGo();

	//Create Retail Park Function (3)
	CGameSquare* CreateRetailPark();

	//Create Bonus Function (4)
	CGameSquare* CreateBonus();

	//Create Penalty Function (5)
	CGameSquare* CreatePenalty();

	//Create Jail Function (6)
	CGameSquare* CreateJail();

	//Create Go to Jail Function (7)
	CGameSquare* CreateGoToJail();

	//Create Free Parking Function (8)
	CGameSquare* CreateFreeParking();

	void AssociateProperty(CPropertySquare* piNewProp);

public:
	//Constructor
	CSquareFactory();

	//Destructor
	~CSquareFactory();

	//Load From file function
	void LoadSquares(string fileName, vector<CGameSquare*>* piList);

};


#endif