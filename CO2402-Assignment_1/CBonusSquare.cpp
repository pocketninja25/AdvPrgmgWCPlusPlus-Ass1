#include "CBonusSquare.h"
#include "Random.h"
#include <sstream>

CBonusSquare::CBonusSquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_BONUS)
{
	//No additional construction
}

CBonusSquare::~CBonusSquare()
{
	//Nothing to destruct
}

string CBonusSquare::OnPassOver(CPlayer* pPassingPlayer)
{
	//Nothing Happens - Return Blank String
	return "";
}

string CBonusSquare::OnLand(CPlayer* pLandingPlayer)
{
	//Generate a random number - this determines the bonus event that occurs
	int eventID = Random();
	//Create output stream
	stringstream out;
	 
	int amountGained = 0;	//The amount of money the player gains from this bonus

	//Output the event name and set the amount of money the player gains
	switch (eventID)
	{
	case 1:
		out << "Find Some Money: ";
		amountGained = 20;
		break;
	case 2:
		out << "Win Competition: ";
		amountGained = 50;
		break;
	case 3:
		out << "Tax Rebate: ";
		amountGained = 100;
		break;
	case 4:
		out << "Win Lottery: ";
		amountGained = 150;
		break;
	case 5:
		out << "Bequest: ";
		amountGained = 200;
		break;
	case 6:
		out << "Birthday: ";
		amountGained = 300;
		break;
	default:
		break;
	}

	//Finish the output (this is output regardless of the bonus selected
	out << pLandingPlayer->GetName() << " Gains " << gPOUND << amountGained << endl;
	//Give the player the specified amount of money for the bonus they landed on
	pLandingPlayer->GiveCash(amountGained);

	//Convert the output to a string and return it
	return out.str();
}