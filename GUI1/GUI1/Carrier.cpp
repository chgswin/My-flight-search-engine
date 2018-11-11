#include "stdafx.h"

Carrier::Carrier(string aviationCode, string name)
{
	aName = name;
	aAviationCode = aviationCode;
}
Carrier::Carrier(const Carrier& c)
{
	aName = c.aName;
	aAviationCode = c.aAviationCode;
}

string Carrier::GetName()
{
	return aName;
}
string Carrier::GetAviationCode()
{
	return aAviationCode;
}
bool Carrier::AreYou(string code)
{
	if (code == aAviationCode) return true;
	if (code == aName) return true;
	return false;
}
