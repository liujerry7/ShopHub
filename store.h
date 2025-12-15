#pragma once

#include <string>
#include <vector>
#include "merchandise.h"

using namespace std;

class Store {
public:
	Store(string newName) {
		name = newName;
	}

	string getName() {
		return name;
	}

	vector<Merchandise> getMerch() {
		return merch;
	}

	void setMerch(vector<Merchandise> newMerch) {
		merch = newMerch;
	}

	void addMerch(Merchandise m) {
		merch.push_back(m);
	}

	void sell(Merchandise m) {
		for (auto& storeMerch : merch) {
			if (storeMerch.getName() == m.getName()) {
				storeMerch.addQuantity(-m.getQuantity());
			}
		}
	}

private:
	string name;
	vector<Merchandise> merch;
};
