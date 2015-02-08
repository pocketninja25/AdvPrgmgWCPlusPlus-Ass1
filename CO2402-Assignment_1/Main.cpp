//Memory Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW_PLACEMENT (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW_PLACEMENT
#endif

//Game Libraries
#include "CMonopoly.h"

using std::cin;
using std::getline;

int main()
{
	const int NO_OF_PLAYERS = 2;	//No of players playing game
	const int NO_OF_ROUNDS = 20;	//No of rounds in the game

	//Create monopoly engine object - parameter is an amount of players
	CMonopoly* pMyGame = CMonopoly::GetInstance(NO_OF_PLAYERS);

	//pMyGame->OutputBoard();

	//Play 20 rounds of monopoly (each player has 20 turns)
	pMyGame->PlayNoRounds(NO_OF_ROUNDS);

	//Clean memory
	delete pMyGame;

	/* EXAMPLE MAIN CODE */

	//CREATE MONOPOLY

	//FOR 20 ROUNDS
	//CALL MONOPOLY->ADVANCE TURN
	//END FOR

	//CALL MONOPOLY->REPORT RESULTS

	//SYSTEM PAUSE

	/* END OF EXAMPLE MAIN CODE */

	//Check for memory leaks
	_CrtDumpMemoryLeaks();
}