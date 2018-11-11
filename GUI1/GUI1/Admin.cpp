#include "stdafx.h"

Admin::Admin(string ID, string password) : User(ID, password)
{
}

bool Admin::IsAdmin()
{
	return true;
}


