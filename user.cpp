#include "user.h"

User::User(string newUsername, string newPassword, float newBalance) {
	username = newUsername;
	password = newPassword;
	balance = newBalance;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

ostream& operator<<(ostream& os, const User& u) {
	os << u.username << ", " << u.balance;
	return os;
}