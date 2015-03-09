#include "CMonopoly.h"

#ifdef _DEBUG
#define DEBUG_NEW_PLACEMENT (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW_PLACEMENT
#endif

CMonopoly* CMonopoly::mpInstance = 0;	//Initialise static variable

CMonopoly* CMonopoly::GetInstance(int noPlayers)					//Used in leiu of a constructor - prevents multiple instances of CMonopoly existing (forces singleton)
{
	if (!mpInstance)	//If an instance does not already exist
	{
		//Make mInstance a new instance of CMonopoly
		mpInstance = new DEBUG_NEW_PLACEMENT CMonopoly(noPlayers);
	}
	//else just return the existing instance

	return mpInstance;

}

int CMonopoly::GetSeed(string filename)			//Reads a seed value from file
{
	ifstream inStream = ifstream(filename);

	int seed = 0;
	inStream >> seed;

	return seed;
}

CMonopoly::CMonopoly(int noPlayers)				//Constructor - can only be called from in class to force a singleton
{
	//Set the random seed for the game
	srand(GetSeed("seed.txt"));

	//Call factory to create a set of squares from the file "Monopoly.txt"
	mSquareCreation.LoadSquares("Monopoly.txt", &mGameBoard);

	//Create 'noPlayers' amount of players - up to the maximum number of pieces in the game
	for (int i = 0; i < PIECE_SIZE && i < noPlayers; i++)
	{
		mPlayers.push_back(new DEBUG_NEW_PLACEMENT CPlayer( (EPlayerPieces)i) );	//Push a new Player with piece index 'i' (casted to EPlayerPieces)
	}
	mTurnNo = 0;	//Set turn number to 0
	
	//Output welcome message
	cout << "Welcome To Monopoly" << endl << endl;
	cout << "You are playing a " << mPlayers.size() << " player game" << endl;
}

CMonopoly::~CMonopoly()
{
	if (mpInstance)
	{
		//Delete then remove each square of mGameBoard
		while (!mGameBoard.empty())
		{
			delete mGameBoard.back();
			mGameBoard.pop_back();
		}
		//Delete then remove each player from the game
		while (!mPlayers.empty())
		{
			delete mPlayers.back();
			mPlayers.pop_back();
		}
	}

	//There is no instance now - set the static value as such
	mpInstance = 0;
}

void CMonopoly::OutputBoard()	//Output the name of each piece on the board in order
{
	for (vector<CGameSquare*>::iterator it = mGameBoard.begin(); it != mGameBoard.end(); it++)
	{
		cout << (*it)->GetName() << endl;
	}
}

void CMonopoly::PlayRound()
{
	mTurnNo++;	//New turn
	cout << endl << "Round No: " << mTurnNo << endl;

	//Initialise roll and pointers
	int roll = 0;
	CGameSquare* pCurrentSquare = 0;
	CPlayer* pCurrentPlayer = 0;

	cout << endl;

	for (vector<CPlayer*>::iterator player = mPlayers.begin(); player != mPlayers.end(); player++)	//Loop through each player performing their turn one at a time
	{
		//Set the current player
		pCurrentPlayer = *player;
		//Roll the dice
		roll = Random();
		
		cout << pCurrentPlayer->GetName() << " Rolls a " << roll << endl;	//Roll Output

		for (int i = 1; i <= roll; i++)	//Follow through the roll moving one space at a time
		{
			//Increment board position for current player
			pCurrentPlayer->SetBoardPosition(pCurrentPlayer->GetBoardPosition() + 1);

			//Loop the piece back to the start of the board - if at the end
			if (pCurrentPlayer->GetBoardPosition() >= mGameBoard.size())
			{
				pCurrentPlayer->SetBoardPosition(0);
			}

			//Set current square the player is on
			pCurrentSquare = mGameBoard.at(pCurrentPlayer->GetBoardPosition());

			if (i != roll)	//If not at the end of the roll
			{
				//Pass over the current square - call event
				cout << pCurrentSquare->OnPassOver(pCurrentPlayer);	//Perform pass over event
			}
			else	//At end of roll - landing on current square (not passing over)
			{
				//Land on the current square
				cout << pCurrentPlayer->GetName() << " lands on " << pCurrentSquare->GetName() << endl;
				cout << pCurrentSquare->OnLand(pCurrentPlayer);		//Perform land event - and output any event text given by the square

				//If the current square put the player in jail - e.g. landed on go to jail
				if (pCurrentPlayer->IsInJail())
				{
					for (unsigned int j = 0; j < mGameBoard.size(); j++)	//Find the jail board space
					{
						if (mGameBoard.at(j)->GetType() == CATEGORY_JAIL)	//Use type to identify generic pointer as specifically the jail space
						{
							//Put player on jail space
							pCurrentPlayer->SetBoardPosition(j);
							pCurrentSquare = mGameBoard.at(j);
							//Perform jail land event
							cout << pCurrentSquare->OnLand(pCurrentPlayer);

							j = mGameBoard.size();	//Escape the loop - no need to keep searching

						}	//End of Jail if
					}	//End of jail search loop

				}	//End of is in jail if
			}	//End of roll event selector

		}	//End of roll loop

		//Output how much money the player has
		cout << pCurrentPlayer->GetName() << " has " << gPOUND << pCurrentPlayer->GetBalance() << endl << endl;

	}	//End Player turns loop
}

void CMonopoly::PlayNoRounds(unsigned int noTurns)	//Play 'noTurns' rounds
{
	//Loop through turns calling the playround function each pass
	for (unsigned int i = 0; i < noTurns; i++)
	{
		this->PlayRound();
		//system("pause");	//Wait for user to confirm round info
	}
}

void CMonopoly::OutputStats()
{
	for (unsigned int i = 0; i < mPlayers.size(); i++)
	{
		cout << mPlayers[i]->GetName() << " has " << gPOUND << mPlayers[i]->GetBalance() << endl;
	}

}