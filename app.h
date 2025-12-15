#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "store.h"
#include "menu.h"

using namespace std;

class App{
public:
	void run();

private:
	int currMenuIdx = 0;
	User *currUser;
	Store* currStore;
	vector<User> users;
	vector<Store> stores;
	vector<Menu *> menus;
};
