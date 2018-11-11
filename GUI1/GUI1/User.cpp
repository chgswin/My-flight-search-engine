#include "stdafx.h"
User::User(string ID, string password) : aPreference()
{
	aPassword = password;
	aID = ID;
}

void User::AddSearchHistory(IHaveAviationCode * e)
{
	aSearchHistory.push_back(e);
}

void User::ClearSearchHistory()
{
	aSearchHistory.clear();
}

string User::GetID()
{
	return aID;
}

string User::GetPassword()
{
	return aPassword;
}

void User::SetPassword(string newPassword)
{
	aPassword = newPassword;
}

vector<IHaveAviationCode*>* User::GetPtrSearchHistory()
{
	return &aSearchHistory;
}

UserPreference* User::GetSearchPreference()
{
	return &aPreference;
}