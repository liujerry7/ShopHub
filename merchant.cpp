#include "merchant.h"

Merchant::Merchant(string newUsername, string newPassword, float newBalance) :
	User(newUsername, newPassword, newBalance) {
}

string Merchant::serialize() {
	return username + "," + password + "," + to_string(balance) + ",y";
}