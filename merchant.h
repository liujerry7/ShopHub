#pragma once

#include <string>
#include "user.h"

using namespace std;

class Merchant : public User {
public:
	// Constructor
	Merchant(string newUsername, string newPassword, float newBalance);

	// Serialization
	string serialize() override;
};