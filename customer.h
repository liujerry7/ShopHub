#pragma once

#include <string>
#include "user.h"

using namespace std;

class Customer : public User {
public:
	// Constructor
	Customer(string newUsername, string newPassword, float newBalance);

	// Serialization
	string serialize() override;
	static Customer deserialize(string txt);
};
