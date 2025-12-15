#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"
#include "app.h"

using namespace std;

class Menu {
public:
	virtual bool prompt() {
		return false;
	}

protected:
	int idx;
	vector<Menu> submenus;
};

class MainMenu : public Menu {
public:
	MainMenu() {
		ifstream db("users.txt");

		string line;
		while (getline(db, line)) {
			vector<string> parts;
			stringstream ss(line);
			string part;

			while (getline(ss, part, ',')) {
				parts.push_back(part);
			}

			User u(parts[0], parts[1], stof(parts[2]));
			users.push_back(u);
		}

		currUser = nullptr;
		idx = 0;

		MallMenu mallMenu;

		submenus.push_back(mallMenu);

		db.close();
	}

	~MainMenu() {
		ofstream db("users.txt");

		for (User& u : users) {
			db << u.getUsername() << ","
				<< u.getPassword() << ","
				<< u.getBalance() << endl;
		}

		db.close();
	}

	bool prompt() override {
		int input;

		cout << "Welcome to ShopHub! " << endl;
		cout << "0: Exit" << endl;
		cout << "1: Register" << endl;
		cout << "2: Login" << endl;
		cout << "3: List Users" << endl;

		cin >> input;

		switch (input) {
			case 0: {
				return true;
			}
			case 1: {
				string username;
				string password;

				cout << "Enter username:" << endl;
				cin >> username;
				cout << "Enter password:" << endl;
				cin >> password;

				User u(username, password, 0);
				users.push_back(u);
				
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
					if (
						users[i].getUsername() == username &&
						users[i].getPassword() == password
					) {
						cout << "Login successful" << endl;
					}
				}

				break;
			}
			default: {
				cout << "Invalid choice." << endl;
				break;
			}
		}

		return false;
	}

private:
	User* currUser;
	vector<User> users;
};

class MallMenu : public Menu {
public:
	MallMenu() {

	}

	~MallMenu() {

	}

	bool prompt() override {
		int input;

		cout << "Logged in as: username" << endl;
		cout << "0: Exit" << endl;
		cout << "1: Logout" << endl;
		cout << "2: List stores" << endl;
		cout << "3: Add store" << endl;
		cout << "4: Select store" << endl;

		cin >> input;

		switch (input) {
			case 0: {
				return true;
			}
			default: {
				cout << "Invalid choice." << endl;
				break;
			}
		}

		return false;
	}

private:
	Store* currStore;
	vector<Store> stores;
};