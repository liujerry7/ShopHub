#pragma once

#include <iostream>
#include <string>

using namespace std;

class User {
public:
	User(string newUsername, string newPassword, float newBalance);

	string getUsername();
	string getPassword();

	friend ostream& operator<<(ostream& os, const User& u);

private:
	string username;
	string password;
	float balance;
};
