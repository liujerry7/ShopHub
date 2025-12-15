#pragma once

#include <string>

using namespace std;

class Merchandise {
public:
	Merchandise(string newName, float newPrice, int newQuantity) {
		name = newName;
		price = newPrice;
		quantity = newQuantity;
	}

	string getName() {
		return name;
	}

	float getPrice() {
		return price;
	}

	int getQuantity() {
		return quantity;
	}

	void addQuantity(int amount) {
		quantity += amount;
	}

	string serialize() {
		return name + "," + to_string(price) + "," + to_string(quantity);
	}

private:
	string name;
	float price;
	int quantity;
};
