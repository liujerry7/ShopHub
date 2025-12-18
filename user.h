#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "merchandise.h"

using namespace std;

class User {
public:
	// Constructor
	User(string newUsername, string newPassword, float newBalance);

	// Desctructor
	virtual ~User() = default;

	// Getters
	string getUsername();
	string getPassword();
	float getBalance();
	vector<Merchandise> getMerch();

	// Setters
	void setMerch(vector<Merchandise> newMerch);

	// User logic
	void buy(Merchandise m);
	void addMerch(Merchandise m);

	// Serialization logic
	virtual string serialize() = 0;

protected:
	vector<Merchandise> merch;
	string username;
	string password;
	float balance;
};
