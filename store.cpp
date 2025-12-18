#include "store.h"

Store::Store(string newName) {
	name = newName;
}

string Store::getName() {
	return name;
}

vector<Merchandise> Store::getMerch() {
	return merch;
}

void Store::setMerch(vector<Merchandise> newMerch) {
	merch = newMerch;
}

void Store::addMerch(Merchandise m) {
	merch.push_back(m);
}

void Store::sell(Merchandise m) {
	for (auto& storeMerch : merch) {
		if (storeMerch.getName() == m.getName()) {
			storeMerch.addQuantity(-m.getQuantity());
		}
	}
}