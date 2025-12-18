#include "user.h"

User::User(string newUsername, string newPassword, float newBalance)
	: username(newUsername), password(newPassword), balance(newBalance) {}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

float User::getBalance() {
	return balance;
}

vector<Merchandise> User::getMerch() {
	return merch;
}

void User::setMerch(vector<Merchandise> newMerch) {
	merch = newMerch;
}

void User::buy(Merchandise m) {
	bool exists = false;

	for (auto& userMerch : merch) {
		if (userMerch.getName() == m.getName()) {
			userMerch.addQuantity(m.getQuantity());
			exists = true;
		}
	}

	if (!exists) {
		merch.push_back(m);
	}

	balance -= m.getPrice() * m.getQuantity();
}

void User::addMerch(Merchandise m) {
	merch.push_back(m);
}