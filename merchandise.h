#pragma once

#include <string>

using namespace std;

class Merchandise {
public:
	// Constructor
	Merchandise(string newName, float newPrice, int newQuantity);

	// Getters
	string getName();
	float getPrice();
	int getQuantity();

	// Domain logic
	void addQuantity(int amount);

	// Serializers
	string serialize();

private:
	string name;
	float price;
	int quantity;
};
