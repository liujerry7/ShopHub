#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Customer.h"

using namespace std;

Customer::Customer(const string name, double initialBalance) : name(name), balance(initialBalance) {}

string Customer::getName() const {
    return name;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::addCharge(double price) {
    balance -= price;
    if (balance < 0) {
        cout << "Credit denied." << cart[i].first << "wasn't purchased"
        balance = 0;
    }
}

void Customer::processRefund(double price) {
    balance += price;
    
}

void Customer::addPurchase(const string& itemName, double price) {
    purchases.push_back(make_pair(itemName, price));
}

vector<pair<string, double>>Customer::getPurchases() const {
    return purchases;
}
