#include "customer.h"

Customer::Customer(string newUsername, string newPassword, float newBalance) :
	User(newUsername, newPassword, newBalance) {
}

string Customer::serialize() {
	return username + "," + password + "," + to_string(balance) + ",n";
}

Customer Customer::deserialize(string txt) {
}