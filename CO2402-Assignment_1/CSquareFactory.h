#ifndef CSQUAREFACTORY_H
#define CSQUAREFACTORY_H

#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;

//Include headers for various square types
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
	vector<CGameSquare*>* mpSquareList;	//A pointer to the list of squares square factory is generating
	ifstream mInStream;					//The file stream being used to read in the game board file

	//Get the name of a square - reads it from the file
	string GetName();

	/* Creator Functions */ //Create an instance of that kind of game square by reading from file*/

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

	/*End of creator functions*/

	//Associates a newly generated CPropertySquare with any CPropertySquares already
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