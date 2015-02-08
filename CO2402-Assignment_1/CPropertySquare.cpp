#include "CPropertySquare.h"
#include <sstream>

CPropertySquare::CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent) : CGameSquare(iSquareName, CATEGORY_PROPERTY)
{
	//Set passed values - and initialise owner to 0 (no owner)
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
	//Nothing Happens - return blank string
	return "";
}

string CPropertySquare::OnLand(CPlayer* pLandingPlayer)
{
	//Output stream - to properly format the output and easily combine strings etc
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
		else	//Not enough money to buy
		{
			out << pLandingPlayer->GetName() << " cannot afford " << this->GetName() << endl;
		}
	}
	else	//Property already owned
	{
		if (pLandingPlayer != mpOwner)	//If landing player is not the owner of the property
		{
			//Pay rent
			pLandingPlayer->TakeCash(this->GetRent());	//Take rent from lander
			mpOwner->GiveCash(this->GetRent());			//Give rent to owner

			//Generate output message
			out << this->GetName() << " is owned by " << mpOwner->GetName() << endl;
			out << pLandingPlayer->GetName() << " pays " << mpOwner->GetName() << " " << gPOUND << this->GetRent() << " in rent" << endl;
		}
		else	//Landing player is the owner of the property - no rent to be paid
		{
			//Generate output message
			out << pLandingPlayer->GetName() << " already owns " << this->GetName() << endl;
		}

	}
	
	//Return output string
	return out.str();
}

void CPropertySquare::AddGroupMember (CPropertySquare* pNewMember)	//Add a new member to this property's group list
{
	bool alreadyIn = false;		//Whether or not the list already contains the 'pNewMember'
	for (int i = 0; i < mGroupMembers.size() && !alreadyIn; i++)	//Loop through vector
	{
		if (mGroupMembers[i] == pNewMember)	//If an existing group member is the same as the proposed new member
		{
			alreadyIn = true;		//Member is already in the list - stop the loop
		}
	}
	if (!alreadyIn)	//If the member is not already in the list
	{
		mGroupMembers.push_back(pNewMember);	//Add member to list
	}
}

int CPropertySquare::GetRent()
{
	bool groupOwned = true;	//Assume group is fully owned - test for ways it is not fully owned
	for (vector<CPropertySquare*>::iterator it = mGroupMembers.begin(); it != mGroupMembers.end() && groupOwned; it++)	//Count through other group members until end of list is reached or the group is proven unowned
	{
		if ((*it)->mpOwner == 0)		//If the member's owner is 0 then it has no owner
		{
			//If a single member has no owner then the group is not fully owned
			groupOwned = false;	//Jump out of loop
		}
		else	//Member has an owner
		{
			if ((*it)->mpOwner != this->mpOwner)	//Test if other group member has same owner as this property
			{
				//Other group member does not have the same owner as this, group is not fully owned
				groupOwned = false;	//Jump out of loop
			}
		}
	}

	if (groupOwned)	//If the group is fully owned
	{
		return mRent * 2;	//Return double the rent (but dont modify its beginning value)
	}
	return mRent;	//Return standard rent
}

EPropertyGroup CPropertySquare::GetPropertyGroup()	//Getter for mGroup
{
	return mGroup;
}