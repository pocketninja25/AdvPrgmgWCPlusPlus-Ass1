#include "CBonusSquare.h"

#include "Random.h"
#include <sstream>

CBonusSquare::CBonusSquare(string iSquareName) : CGameSquare(iSquareName)
{
	//No additional construction
}

CBonusSquare::~CBonusSquare()
{
	//Nothing to destruct
}

string CBonusSquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens - Return Blank Text
	return "";
}

string CBonusSquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	int eventID = Random();
	stringstream out;
	 
	out << landingPlayer->GetName() << " lands on Bonus" << endl;
	int amountGained = 0;

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
	out << landingPlayer->GetName() << " Gains " << POUND << amountGained << endl;
	landingPlayer->GiveCash(amountGained);
	out << landingPlayer->GetName() << " has " << POUND << landingPlayer->GetBalance() << endl;

	return out.str();
}