#include "CPenaltySquare.h"
#include <sstream>

CPenaltySquare::CPenaltySquare(string iSquareName) : CGameSquare(iSquareName, CATEGORY_PENALTY)
{
	//No additional construction
}

CPenaltySquare::~CPenaltySquare()
{
	//Nothing to destruct
}

string CPenaltySquare::OnPassOver(CPlayer* passingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Nothing Happens
	return "";
}

string CPenaltySquare::OnLand(CPlayer* landingPlayer)	//This function will need to return any output statements either via stringstream or string
{
	//Generate a random number - this determines the penalty event that occurs
	int eventID = Random();
	//Create output stream
	stringstream out;

	int amountLost = 0;	//The amount of money the player gains from this bonus

	//Output the event name and set the amount of money the player gains
	switch (eventID)
	{
	case 1:

		out << "Pay food bill: ";
		amountLost = 20;
		break;
	case 2:
		out << "Pay phone bill: ";
		amountLost = 50;
		break;
	case 3:
		out << "Pay heating bill: ";
		amountLost = 100;
		break;
	case 4:
		out << "Pay vehicle tax: ";
		amountLost = 150;
		break;
	case 5:
		out << "Pay fuel bill: ";
		amountLost = 200;
		break;
	case 6:
		out << "Pay windfall tax: ";
		amountLost = 300;
		break;
	default:
		break;
	}

	//Finish the output (this is output regardless of the bonus selected
	out << landingPlayer->GetName() << " loses " << gPOUND << amountLost << endl;
	//Give the player the specified amount of money for the bonus they landed on
	landingPlayer->TakeCash(amountLost);

	//Convert the output to a string and return it
	return out.str();
}