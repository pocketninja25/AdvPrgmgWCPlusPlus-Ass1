#ifndef CPROPERTYSQUARE_H
#define CPROPERTYSQUARE_H

#include "CGameSquare.h"

//Type 1 Square

class CPropertySquare : public CGameSquare
{
private:
	EPropertyGroup mGroup;					//This property's colour group
	int mPurchaseCost;						//The cost to purchase this property
	int mRent;								//The rent to pay when landing on this purchased property
	CPlayer* mpOwner;						//A pointer to the owner of this property
	vector<CPropertySquare*> mGroupMembers;	//Vector of properties in the same group

public:
	//Constructor
	CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent);

	//Destructor
	virtual ~CPropertySquare();

	//Pass over event
	string OnPassOver(CPlayer* pPassingPlayer);

	//Land event
	string OnLand(CPlayer* pLandingPlayer);

	void AddGroupMember(CPropertySquare* pNewMember);	//Add knowledge of another propertysquare in the same group as this one

	//Returns the rent to pay for this property
	int GetRent();

	//Returns the property group this property belongs to
	EPropertyGroup GetPropertyGroup();
};

#endif