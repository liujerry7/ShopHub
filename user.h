#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "merchandise.h"

using namespace std;

class User {
public:
	User(string newUsername, string newPassword, float newBalance) {
		username = newUsername;
		password = newPassword;
		balance = newBalance;
	}

	virtual ~User() = default;

	string getUsername() {
		return username;
	}

	string getPassword() {
		return password;
	}

	float getBalance() {
		return balance;
	}

	vector<Merchandise> getMerch() {
		return merch;
	}

	void buy(Merchandise m) {
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

	void setMerch(vector<Merchandise> newMerch) {
		merch = newMerch;
	}

	void addMerch(Merchandise m) {
		merch.push_back(m);
	}

	virtual string serialize() = 0;

protected:
	vector<Merchandise> merch;
	string username;
	string password;
	float balance;
};
