#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>
#include "user.h"
#include "store.h"
#include "customer.h"
#include "merchant.h"
#include "merchandise.h"

using namespace std;

class App {
public:
	App() {
		ifstream usersDb("users.txt");
		ifstream storesDb("stores.txt");
		ifstream userMerchDb("user_merch.txt");
		ifstream storeMerchDb("store_merch.txt");

		string line;
		
		while (getline(usersDb, line)) {
			vector<string> parts;
			stringstream ss(line);
			string part;

			while (getline(ss, part, ',')) {
				parts.push_back(part);
			}

			if (parts[3] == "y") {
				unique_ptr<User> u = make_unique<Merchant>(parts[0], parts[1], stof(parts[2]));
				vector<Merchandise> merch;

				while (getline(userMerchDb, line)) {
					vector<string> merchParts;
					stringstream ss(line);
					string merchPart;

					while (getline(ss, merchPart, ',')) {
						merchParts.push_back(merchPart);
					}

					if (merchParts[3] == u->getUsername()) {
						Merchandise m(merchParts[0], stof(merchParts[1]), stoi(merchParts[2]));
						merch.push_back(m);
					}
				}

				u->setMerch(merch);
				users.push_back(move(u));
			}
			else if (parts[3] == "n") {
				unique_ptr<User> u = make_unique<Customer>(parts[0], parts[1], stof(parts[2]));
				vector<Merchandise> merch;

				while (getline(userMerchDb, line)) {
					vector<string> merchParts;
					stringstream ss(line);
					string merchPart;

					while (getline(ss, merchPart, ',')) {
						merchParts.push_back(merchPart);
					}

					if (merchParts[3] == u->getUsername()) {
						Merchandise m(merchParts[0], stof(merchParts[1]), stoi(merchParts[2]));
						merch.push_back(m);
					}
				}

				u->setMerch(merch);
				users.push_back(move(u));
			}
			else {
				cout << "Error deserializing user." << endl;
			}

			userMerchDb.clear();
			userMerchDb.seekg(0);
		}

		while (getline(storesDb, line)) {
			vector<string> parts;
			stringstream ss(line);
			string part;

			while (getline(ss, part, ',')) {
				parts.push_back(part);
			}

			unique_ptr<Store> s = make_unique<Store>(parts[0]);
			vector<Merchandise> merch;

			while (getline(storeMerchDb, line)) {
				vector<string> merchParts;
				stringstream ss(line);
				string merchPart;

				while (getline(ss, merchPart, ',')) {
					merchParts.push_back(merchPart);
				}

				if (merchParts[3] == s->getName()) {
					Merchandise m(merchParts[0], stof(merchParts[1]), stoi(merchParts[2]));
					merch.push_back(m);
				}
			}

			s->setMerch(merch);
			stores.push_back(move(s));

			storeMerchDb.clear();
			storeMerchDb.seekg(0);
		}

		currUser = nullptr;
		currStore = nullptr;

		usersDb.close();
		storesDb.close();
		userMerchDb.close();
		storeMerchDb.close();
	}

	~App() {
		ofstream usersDb("users.txt");
		ofstream storesDb("stores.txt");
		ofstream userMerchDb("user_merch.txt");
		ofstream storeMerchDb("store_merch.txt");

		for (const auto& u : users) {
			usersDb << u->serialize() << endl;

			for (auto& m : u->getMerch()) {
				string merchSerialized = m.serialize() + "," + u->getUsername();
				userMerchDb << merchSerialized << endl;
			}
		}

		for (const auto& s : stores) {
			storesDb << s->getName() << endl;

			for (auto& m : s->getMerch()) {
				string merchSerialized = m.serialize() + "," + s->getName();
				storeMerchDb << merchSerialized << endl;
			}
		}
	}

	void run() {
		bool exiting = false;

		while (!exiting) {
			int input;

			if (currUser == nullptr) {
				cout << "Welcome to ShopHub! " << endl;
				cout << "0: Exit" << endl;
				cout << "1: Register" << endl;
				cout << "2: Login" << endl;
				cout << "3: List Users" << endl;
				cin >> input;

				switch (input) {
				case 0: {
					cout << "Goodbye!" << endl;
					exiting = true;
					break;
				}
				case 1: {
					string username;
					string password;
					string isMerchant;
					float balance = 0.0f;

					cout << "Enter username:" << endl;
					cin >> username;
					cout << "Enter password:" << endl;
					cin >> password;
					cout << "Are you a merchant? (y/n)" << endl;
					cin >> isMerchant;
					cout << "Enter balance:" << endl;
					cin >> balance;

					if (isMerchant == "y") {
						users.push_back(make_unique<Merchant>(username, password, balance));
					}
					else if (isMerchant == "n") {
						users.push_back(make_unique<Customer>(username, password, balance));
					}
					else {
						cout << "Invalid option." << endl;
					}

					break;
				}
				case 2: {
					string username;
					string password;

					cout << "Enter username:" << endl;
					cin >> username;
					cout << "Enter password:" << endl;
					cin >> password;

					for (int i = 0; i < users.size(); i++) {
						if (users[i]->getUsername() == username &&
							users[i]->getPassword() == password) {
							currUser = users[i].get();
							cout << "Login successful" << endl;
						}
					}

					break;
				}
				case 3: {
					cout << fixed << setprecision(2);
					cout << "--- Users ---" << endl;

					for (const auto& u : users) {
						cout << u->getUsername() << ", " << u->getBalance() << endl;
					}

					break;
				}
				default: {
					cout << "Invalid choice." << endl;
					break;
				}
				}
			}
			else {
				cout << "Logged in as: " << currUser->getUsername() << endl;

				if (currStore == nullptr) {
					if (typeid(*currUser) == typeid(Customer)) {
						cout << "0: Exit" << endl;
						cout << "1. Logout" << endl;
						cout << "2. List stores" << endl;
						cout << "3. Select store" << endl;
						cout << "4. List merchandise" << endl;

						cin >> input;

						switch (input) {
						case 0: {
							cout << "Goodbye!" << endl;
							exiting = true;
							break;
						}
						case 1: {
							currUser = nullptr;
							break;
						}
						case 2: {
							cout << "--- Stores ---" << endl;

							for (const auto& s : stores) {
								cout << s->getName() << endl;
							}

							break;
						}
						case 3: {
							string storeName;

							cout << "Enter store name:" << endl;
							cin >> storeName;

							for (int i = 0; i < stores.size(); i++) {
								if (stores[i]->getName() == storeName) {
									currStore = stores[i].get();
									cout << "Selected " << storeName << endl;
								}
							}

							break;
						}
						case 4: {
							cout << "--- Merchandise ---" << endl;

							for (auto& m : currUser->getMerch()) {
								cout << fixed << setprecision(2);
								cout << m.getName() << ", $"
									<< m.getPrice() << ", "
									<< m.getQuantity() << endl;
							}

							break;
						}
						default: {
							cout << "Invalid choice." << endl;
							break;
						}
						}
					}
					else if (typeid(*currUser) == typeid(Merchant)) {
						cout << "0: Exit" << endl;
						cout << "1. Logout" << endl;
						cout << "2. List stores" << endl;
						cout << "3. Select store" << endl;
						cout << "4. Add store" << endl;

						cin >> input;

						switch (input) {
						case 0: {
							cout << "Goodbye!" << endl;
							exiting = true;
							break;
						}
						case 1: {
							currUser = nullptr;
							currStore = nullptr;
							break;
						}
						case 2: {
							cout << "--- Stores ---" << endl;

							for (const auto& s : stores) {
								cout << s->getName() << endl;
							}

							break;
						}
						case 3: {
							string storeName;

							cout << "Enter store name:" << endl;
							cin >> storeName;

							for (int i = 0; i < stores.size(); i++) {
								if (stores[i]->getName() == storeName) {
									currStore = stores[i].get();
									cout << "Selected " << storeName << endl;
								}
							}

							break;
						}
						case 4: {
							string storeName;

							cout << "Enter store name:" << endl;
							cin >> storeName;

							stores.push_back(make_unique<Store>(storeName));

							break;
						}
						default: {
							cout << "Invalid choice." << endl;
							break;
						}
						}
					}
				}
				else {
					cout << "Visiting store: " << currStore->getName() << endl;

					if (typeid(*currUser) == typeid(Customer)) {
						cout << "0: Exit" << endl;
						cout << "1. Logout" << endl;
						cout << "2. List merchandise" << endl;
						cout << "3. Buy merchandise" << endl;

						cin >> input;

						switch (input) {
						case 0: {
							cout << "Goodbye!" << endl;
							exiting = true;
							break;
						}
						case 1: {
							currUser = nullptr;
							currStore = nullptr;
							break;
						}
						case 2: {
							cout << "--- Merchandise ---" << endl;
							for (auto& m : currStore->getMerch()) {
								cout << fixed << setprecision(2);
								cout << m.getName() << ", $"
									<< m.getPrice() << ", "
									<< m.getQuantity() << endl;
							}
							break;
						}
						case 3: {
							string merchName;
							int merchQuantity;

							cout << "Enter merchandise name:" << endl;
							cin >> merchName;
							cout << "Enter merchandise quantity:" << endl;
							cin >> merchQuantity;
							
							for (auto& m : currStore->getMerch()) {
								if (m.getName() == merchName) {
									Merchandise transaction(m.getName(), m.getPrice(), merchQuantity);
									currUser->buy(transaction);
									currStore->sell(transaction);

									cout << "Your checkout is complete!" << endl;
								}
							}

							break;
						}
						default: {
							cout << "Invalid choice." << endl;
							break;
						}
						}
					}
					else if (typeid(*currUser) == typeid(Merchant)) {
						cout << "0: Exit" << endl;
						cout << "1. Logout" << endl;
						cout << "2. List merchandise" << endl;
						cout << "3. Add merchandise" << endl;

						cin >> input;
						
						switch (input) {
						case 0: {
							cout << "Goodbye!" << endl;
							exiting = true;
							break;
						} 
						case 1: {
							currUser = nullptr;
							break;
						}
						case 2: {
							cout << "--- Merchandise ---" << endl;
							for (auto& m : currStore->getMerch()) {
								cout << fixed << setprecision(2);
								cout << m.getName() << ", $"
									<< m.getPrice() << ", "
									<< m.getQuantity() << endl;
							}
							break;
						}
						case 3: {
							string merchName;
							float merchPrice = 0.0f;
							int merchQuantity;

							cout << "Enter merch name:" << endl;
							cin >> merchName;
							cout << "Enter merch price:" << endl;
							cin >> merchPrice;
							cout << "Enter merch quantity:" << endl;
							cin >> merchQuantity;

							Merchandise m(merchName, merchPrice, merchQuantity);
							currStore->addMerch(m);

							break;
						}
						default: {
							cout << "Invalid choice." << endl;
							break;
						}
						}
					}
				}
			}
		}
	}

private:
	User* currUser;
	Store* currStore;
	vector<unique_ptr<User>> users;
	vector<unique_ptr<Store>> stores;
};
