#include "merchandise.h"

Merchandise::Merchandise(string newName, float newPrice, int newQuantity) {
	name = newName;
	price = newPrice;
	quantity = newQuantity;
}

string Merchandise::getName() {
	return name;
}

float Merchandise::getPrice() {
	return price;
}

int Merchandise::getQuantity() {
	return quantity;
}

void Merchandise::addQuantity(int amount) {
	quantity += amount;
}

string Merchandise::serialize() {
	return name + "," + to_string(price) + "," + to_string(quantity);
}