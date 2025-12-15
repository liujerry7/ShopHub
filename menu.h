#pragma once

#include <iostream>

using namespace std;

class Menu {
public:
	virtual void prompt() {};
};

class MainMenu : public Menu {
	void prompt() override {
		int input;

		cout << "Welcome to ShopHub! " << endl;
		cout << "0: Exit" << endl;
		cout << "1: Register" << endl;
		cout << "2: Login" << endl;
		cout << "3: List Users" << endl;

		cin >> input;
		switch (input) {

		}
	}
};