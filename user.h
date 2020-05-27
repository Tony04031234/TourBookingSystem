#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class User
{
    public:

    	User();// constructor

    	User(string, string);

    	virtual bool isLogin(string,string )=0;

    	// View the Tour which is being sold
        void viewLocation();

    	// Encapsualation for username
    	void setUsername(string);
    	string getUsername() const;

    	//Encapsualation for password
    	void setPassword(string passWord);
    	string getPassword() const;


    	~User(); // destructor

    protected:
    	string username;
    	string password;
};

#endif