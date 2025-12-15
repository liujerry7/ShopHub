#pragma once

#include <string>
#include "user.h"

using namespace std;

class Merchant : public User {
public:
	Merchant(string newUsername, string newPassword, float newBalance) :
		User(newUsername, newPassword, newBalance) {
	}

	string serialize() override {
		return username + "," + password + "," + to_string(balance) +",y";
	}
};