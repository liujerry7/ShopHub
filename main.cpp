#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "user.h"

using namespace std;

int main() {
	bool exiting = false;
	bool authenticated = false;

	while (!exiting) {
		int input;

		if (authenticated) {
			cout << "Logged in as: username" << endl;
			cout << "0: Exit" << endl;
			cout << "1: Logout" << endl;
			cout << "2: List stores" << endl;
			cout << "3: Add store" << endl;
			cout << "4: Select store" << endl;
			cin >> input;         

			switch (input) {
				case 0: {
					cout << "Goodbye!" << endl;
					exiting = true;
					break;
				}
				case 1: {
					authenticated = false;
					break;
				}
				default: {
					cout << "Invalid choice." << endl;
					break;
				}
			}
		}
		else {
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

					cout << "Enter username:" << endl;
					cin >> username;
					cout << "Enter password:" << endl;
					cin >> password;

					ofstream db("users.txt");
					db << username << ","
						<< password << ","
						<< 0 << endl;

					db.close();
					break;
				}
				case 2: {
					string username;
					string password;

					cout << "Enter username:" << endl;
					cin >> username;
					cout << "Enter password:" << endl;
					cin >> password;

					ifstream db("users.txt");
					vector<User> users;

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

					for (int i = 0; i < users.size(); i++) {
						if (
							users[i].getUsername() == username &&
							users[i].getPassword() == password
							) {
							authenticated = true;
							cout << "Login successful" << endl;
						}
					}

					break;
				}
				case 3: {
					ifstream db("users.txt");
					vector<User> users;

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

					cout << fixed << setprecision(2);
					cout << "--- Users ---" << endl;

					for (const User& u : users) {
						cout << u << endl;
					}

					break;
				}
				default: {
					cout << "Invalid choice." << endl;
					break;
				}
			}
		}
	}

	return 0;
}