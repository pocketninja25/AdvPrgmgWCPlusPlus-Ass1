//Memory Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//Game Libraries
#include "CMonopoly.h"
#include <sstream>

int main()
{
	CMonopoly* pMyGame = new CMonopoly();

	//pMyGame->OutputBoard();

	pMyGame->PlayTurns(20);

	delete pMyGame;
	
	system("pause");

	_CrtDumpMemoryLeaks();
	/* EXAMPLE MAIN CODE */

	//CREATE MONOPOLY

	//FOR 20 ROUNDS
	//CALL MONOPOLY->ADVANCE TURN
	//END FOR

	//CALL MONOPOLY->REPORT RESULTS

	//SYSTEM PAUSE

	/* END OF EXAMPLE MAIN CODE */

	/********MAIN GAME NOTES*********/

	//26 square board 
	//2 Players
	//Default - P1 is dog, P2 is car
	//Players recieve 1500£ at beginning of game - the bank has unlimited money
	//Each player having one move is called a round - in a round each player takes 1 turn
		//- rolls the dice, moves clockwise by num of squares.
	//No user input - game is simulation
	//Play for 20 rounds
	//Welcome message - 'Welcome to Monopoly'

	///****TURN DYNAMICS****//
	//Each turn display '<Player> rolls <number>'
		//- Followed by '<Player> lands on <square name>'
	//if property not owned player will buy it (if positive money)
		//- '<Player> buys <square name> for <cost>’
		//- if property owned by player who landed, nothing happens
		//- if property owned by another player - pay owner a fee of £10
		//- '<Player> pays <rent>’
		//- '<Player> pays £10 flying costs’ - on airports
			//- includes something about if special squares not implemented in the documentation - possibly irrelevant
	//At end of turn display '<Player> has <current balance>’
	///****END OF TURN DYNAMICS****//


	
	/********END MAIN GAME NOTES*******/




}