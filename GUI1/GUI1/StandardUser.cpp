#include "stdafx.h"

StandardUser::StandardUser(string ID, string password) : User(ID, password)
{
}

bool StandardUser::IsAdmin()
{
	return false;
}


