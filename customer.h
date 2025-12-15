#pragma once

#include <string>
#include "user.h"

using namespace std;

class Customer : public User {
public:
	Customer(string newUsername, string newPassword, float newBalance) :
		User(newUsername, newPassword, newBalance) {
	}

	string serialize() override {
		return username + "," + password + "," + to_string(balance) + ",n";
	}
};
