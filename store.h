#pragma once

#include <string>
#include <vector>
#include "merchandise.h"

using namespace std;

class Store {
public:
	// Constructor
	Store(string newName);

	// Getters
	string getName();
	vector<Merchandise> getMerch();

	// Setters
	void setMerch(vector<Merchandise> newMerch);

	// Domain logic
	void addMerch(Merchandise m);
	void sell(Merchandise m);

private:
	string name;
	vector<Merchandise> merch;
};
