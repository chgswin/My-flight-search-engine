#include "stdafx.h"
#include <fstream>
#include <iostream>
const int READ_TIMES_EACH_LINE = 3;

UserControlSingleton* UserControlSingleton::u_Instance = nullptr;

UserControlSingleton* UserControlSingleton::Instance()
{
	if (u_Instance == nullptr)
		u_Instance = new UserControlSingleton();
	return u_Instance;
}

UserControlSingleton::UserControlSingleton()
{
}

bool UserControlSingleton::IsUsernameTaken(string newUsername)
{
	map<string, User*>::iterator it = aUserMap.find(newUsername);
	if (it == aUserMap.end()) return false;
	else return true;
}

void UserControlSingleton::AddUser(User* newUser)
{
	if (newUser == nullptr) return;
	if (!IsUsernameTaken(newUser->GetID()) )
		aUserMap[newUser->GetID()] = newUser;
}

User* UserControlSingleton::GetCurrentUser(string userName, string password)
{
	if (IsUsernameTaken(userName))
	{
		User* newUser = aUserMap[userName];
		if (password == newUser->GetPassword())
			return newUser;
	}
	return nullptr;
}

void UserControlSingleton::LoadData(string filename)
{
	int i;
	vector<string> str;
	string read_str;
	
	ifstream read;
	Factory mapFactory;
	try {
		read.open(filename);
		while (read.good()) {
			for (i = 0; i < READ_TIMES_EACH_LINE - 1; ++i)
			{
				getline(read, read_str, ',');
				str.push_back(read_str);
			}
			getline(read, read_str, '\n');
			str.push_back(read_str);
			AddUser(mapFactory.CreateUser(str));
			str.clear();
		}
	}
	finally
	{
		read.close();
	}
}

void UserControlSingleton::SaveData(string filename)
{
	map<string, User*>::iterator it;
	ofstream write;
	try {
		write.open(filename);
		for (it = aUserMap.begin(); it != aUserMap.end(); ++it)
		{
			if (it->second->IsAdmin())
				write << "Admin,";
			else
				write << "StandardUser,";
			write << it->second->GetID() << "," << it->second->GetPassword();
			if (it != prev(aUserMap.end(), 1)) write << '\n';
		}
	} 
	finally
	{
		write.close();
	}
}

UserControlSingleton::~UserControlSingleton()
{
	map<string, User*>::iterator it;
	for (it = aUserMap.begin(); it != aUserMap.end(); ++it)
	{
		delete it->second;
	}
	aUserMap.clear();
}
