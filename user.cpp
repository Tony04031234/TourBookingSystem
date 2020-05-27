#include "user.h"

User::User(){ //constructor
}

User::User(string username, string password){
}

// Set username
void User::setUsername(string userName)
{
	username = userName;
}

// get username
string User::getUsername() const
{
	return username;
}

// set password
void User::setPassword(string passWord)
{
	password = passWord;
}

// get password
string User::getPassword()  const
{
	return password;
}

User::~User(){ // destructor
}


