#include "CPropertySquare.h"
#include <sstream>

CPropertySquare::CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent) : CGameSquare(iSquareName, CATEGORY_PROPERTY)
{
	mGroup = iGroup;
	mPurchaseCost = iPurchaseCost;
	mRent = iRent;
	mpOwner = 0;
}

CPropertySquare::~CPropertySquare()
{
	//Nothing to destruct
}

string CPropertySquare::OnPassOver(CPlayer* pPassingPlayer)	
{
	//Nothing Happens
	return "";
}

string CPropertySquare::OnLand(CPlayer* pLandingPlayer)
{
	//Output stream
	stringstream out;
	
	//If there is no owner
	if (!mpOwner)
	{
		//If the landing player has a positive bank balance
		if (pLandingPlayer->GetBalance() > 0)
		{
			//Purchase the property
			pLandingPlayer->TakeCash(mPurchaseCost);
			pLandingPlayer->BecomeOwner(this);
			mpOwner = pLandingPlayer;
			out << pLandingPlayer->GetName() << " buys " << this->GetName() << " for " << gPOUND << mPurchaseCost << endl;
		}
		else
		{
			out << pLandingPlayer->GetName() << " cannot afford " << this->GetName() << endl;
		}
	}
	else
	{
		if (pLandingPlayer != mpOwner)
		{
			pLandingPlayer->TakeCash(this->GetRent());
			mpOwner->GiveCash(this->GetRent());
			out << this->GetName() << " is owned by " << mpOwner->GetName() << endl;
			out << pLandingPlayer->GetName() << " pays " << mpOwner->GetName() << " " << gPOUND << this->GetRent() << " in rent" << endl;
		}
		else
		{
			out << pLandingPlayer->GetName() << " already owns " << this->GetName() << endl;
		}

	}
	
	return out.str();
}

void CPropertySquare::AddGroupMember (CPropertySquare* pNewMember)
{
	mGroupMembers.push_back(pNewMember);
}

int CPropertySquare::GetRent()
{
	bool groupOwned = true;	//Assume group is fully owned - test ways it is not fully owned
	for (vector<CPropertySquare*>::iterator it = mGroupMembers.begin(); it != mGroupMembers.end(); it++)	//Count through other group members
	{
		if ((*it) == 0)	
		{
			//Group has no owner, group is not fully owned
			groupOwned = false;	
		}
		else
		{
			if ((*it)->mpOwner != this->mpOwner)
			{
				//Other group member does not have the same owner as this, group is not fully owned
				groupOwned = false;
			}
		}
	}

	if (groupOwned)
	{
		return mRent * 2;
	}
	return mRent;
}

EPropertyGroup CPropertySquare::GetPropertyGroup()
{
	return mGroup;
}