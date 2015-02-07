#ifndef CPROPERTYSQUARE_H
#define CPROPERTYSQUARE_H

#include "CGameSquare.h"

//Type 1 Square

class CPropertySquare : public CGameSquare
{
private:
	EPropertyGroup mGroup;
	int mPurchaseCost;
	int mRent;
	CPlayer* mpOwner;
	vector<CPropertySquare*> mGroupMembers;	//Vector of properties in the same group

public:
	CPropertySquare(string iSquareName, EPropertyGroup iGroup, int iPurchaseCost, int iRent);

	virtual ~CPropertySquare();

	string OnPassOver(CPlayer* pPassingPlayer);

	string OnLand(CPlayer* pLandingPlayer);

	void AddGroupMember(CPropertySquare* pNewMember);	//Add knowledge of another propertysquare in the same group as this one

	int GetRent();

	EPropertyGroup GetPropertyGroup();
};

#endif