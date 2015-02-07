#include "CMonopoly.h"

#ifdef _DEBUG
#define DEBUG_NEW_PLACEMENT (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW_PLACEMENT
#endif

CMonopoly* CMonopoly::mpInstance = 0;

CMonopoly* CMonopoly::GetInstance(int noPlayers)
{
	if (!mpInstance)	//If an instance does not already exist
	{
		//Make mInstance a new instance of CMonopoly
		mpInstance = new DEBUG_NEW_PLACEMENT CMonopoly(noPlayers);
	}
	
	return mpInstance;

}

CMonopoly::CMonopoly(int noPlayers)
{
	srand(4);
	mSquareCreation.LoadSquares("Monopoly.txt", &mGameBoard);
	for (int i = 0; i < PIECE_SIZE && i < noPlayers; i++)
	{
		mPlayers.push_back(new DEBUG_NEW_PLACEMENT CPlayer((EPlayerPieces) i));
	}
	mTurnNo = 0;
	
	cout << "Welcome To Monopoly" << endl;
}

CMonopoly::~CMonopoly()
{
	if (mpInstance)
	{
		while (!mGameBoard.empty())
		{
			delete mGameBoard.back();
			mGameBoard.pop_back();
		}
		while (!mPlayers.empty())
		{
			delete mPlayers.back();
			mPlayers.pop_back();
		}
	}

	//There is no instance
	mpInstance = 0;
}

void CMonopoly::OutputBoard()
{
	for (vector<CGameSquare*>::iterator it = mGameBoard.begin(); it != mGameBoard.end(); it++)
	{
		cout << (*it)->GetName() << endl;
	}
}

void CMonopoly::PlayRound()
{
	mTurnNo++;
	cout << endl << "Round No: " << mTurnNo << endl;

	int roll;
	CGameSquare* pCurrentSquare;
	CPlayer* pCurrentPlayer;
	cout << endl;
	for (vector<CPlayer*>::iterator player = mPlayers.begin(); player != mPlayers.end(); player++)
	{
		pCurrentPlayer = *player;
		roll = Random();
		
		cout << pCurrentPlayer->GetName() << " Rolls a " << roll << endl;

		for (int i = 1; i <= roll; i++)	//Follow through the roll moving one space at a time
		{
			//Increment board position
			pCurrentPlayer->SetBoardPosition(pCurrentPlayer->GetBoardPosition() + 1);


			//Loop the piece back to the start of the board
			if (pCurrentPlayer->GetBoardPosition() >= mGameBoard.size())
			{
				pCurrentPlayer->SetBoardPosition(0);
			}
			//Set current square
			pCurrentSquare = mGameBoard.at(pCurrentPlayer->GetBoardPosition());

			if (i != roll)	//If not at the end of the roll
			{
				//Pass over the current square
				cout << pCurrentSquare->OnPassOver(pCurrentPlayer);	//Perform pass over event
			}
			else	//At end of roll
			{
				//Land on the current square
				cout << pCurrentPlayer->GetName() << " lands on " << pCurrentSquare->GetName() << endl;
				cout << pCurrentSquare->OnLand(pCurrentPlayer);		//Perform land event

				//If the current square put the player in jail
				if (pCurrentPlayer->IsInJail())
				{
					for (unsigned int j = 0; j < mGameBoard.size(); j++)	//Find the jail board space
					{
						if (mGameBoard.at(j)->GetType() == CATEGORY_JAIL)
						{
							//Put player on jail space
							pCurrentPlayer->SetBoardPosition(j);
							pCurrentSquare = mGameBoard.at(j);
							cout << pCurrentSquare->OnLand(pCurrentPlayer);

							j = mGameBoard.size();	//Escape the loop

						}	//End of Jail if
					}	//End of jail search loop

				}	//End of is in jail if
			}	//End of roll event selector

		}	//End of roll loop

		//Output how much money the player has
		cout << pCurrentPlayer->GetName() << " has " << gPOUND << pCurrentPlayer->GetBalance() << endl << endl;

	}	//End Player turns loop
}

void CMonopoly::PlayNoRounds(unsigned int noTurns)
{
	for (unsigned int i = 0; i < noTurns; i++)
	{
		this->PlayRound();
		system("pause");
	}
}