
#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"

#ifndef OTHEROPTIONS_H
#define OTHEROPTIONS_H


void addCustomer(vector<Customer>& customers);
void addMerchandiseToDepartment(vector<pair<string, double>>& department);
void makePurchase(vector<Customer>& customers, vector<pair<string, double>>& department);
void displayMerchandise(vector<pair<string, double>>& department);

#endif