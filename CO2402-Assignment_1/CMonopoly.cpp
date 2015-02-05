#include "CMonopoly.h"

CMonopoly::CMonopoly()
{
	mSquareCreation.LoadSquares("Monopoly.txt", &mGameBoard);
	mPlayers.push_back(new CPlayer(PIECE_DOG));
	mPlayers.push_back(new CPlayer(PIECE_CAR));
	mTurnNo = 0;
}

CMonopoly::~CMonopoly()
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

void CMonopoly::OutputBoard()
{
	for (vector<CGameSquare*>::iterator it = mGameBoard.begin(); it != mGameBoard.end(); it++)
	{
		cout << (*it)->GetName() << endl;
	}
}

void CMonopoly::TakeTurn()
{
	mTurnNo++;
	////cout << "This is turn no: " << mTurnNo << endl;
	 
	int roll;
	CGameSquare* currentSquare;
	CPlayer* currentPlayer;
	for (vector<CPlayer*>::iterator player = mPlayers.begin(); player != mPlayers.end(); player++)
	{
		currentPlayer = *player;
		roll = Random();
		
		////cout << "Player: " << currentPlayer->GetPiece() << " Is on " << mGameBoard.at(currentPlayer->GetBoardPosition())->GetName() << endl;
		////cout << "Player: " << currentPlayer->GetPiece() << " Rolled a " << roll << endl;
		for (int i = 1; i <= roll; i++)
		{
			currentPlayer->SetBoardPosition(currentPlayer->GetBoardPosition() + 1);
			//Loop the piece back to the start of the board
			if (currentPlayer->GetBoardPosition() >= mGameBoard.size())
			{
				currentPlayer->SetBoardPosition(0);
			}
			currentSquare = mGameBoard.at(currentPlayer->GetBoardPosition());

			if (i != roll)
			{
				////cout << "Player: " << currentPlayer->GetPiece() << " passed over " << currentSquare->GetName() << endl;
				
				cout << mGameBoard.at(currentPlayer->GetBoardPosition())->OnPassOver(currentPlayer);
			}
			else
			{
				////cout << "Player: " << currentPlayer->GetPiece() << " landed on " << currentSquare->GetName() << endl;
				cout << mGameBoard.at(currentPlayer->GetBoardPosition())->OnLand(currentPlayer);
			}
		}

		cout << endl << endl;
	}
}

void CMonopoly::PlayTurns(unsigned int noTurns)
{
	for (unsigned int i = 0; i < noTurns; i++)
	{
		this->TakeTurn();
		system("pause");
	}
}