#pragma once

/*
 * File: App.h
 * Author: Jerry Liu
 * Description:
 *   Defines the App class, which serves as the main controller for the ShopHub
 *   application. The App class is responsible for:
 *     - Loading persistent data from files
 *     - Managing application state (current user and store)
 *     - Handling user interaction and menu navigation
 *     - Saving all data back to disk on shutdown
 */

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
#include "exception.h"

using namespace std;

/*
 * Class: App
 * Purpose:
 *   Acts as the main application controller. Owns all users and stores,
 *   manages authentication state, routes UI flow, and coordinates
 *   file-based persistence.
 */
class App {
public:
	/*
	 * Constructor: App
	 * Description:
	 *   Initializes the application by loading users, stores, and
	 *   merchandise data from text-based database files.
	 *
	 *   Files used:
	 *     - users.txt       : User credentials and roles
	 *     - stores.txt      : Store names
	 *     - user_merch.txt  : Merchandise owned by users
	 *     - store_merch.txt : Merchandise available in stores
	 */
	App();

	/*
	 * Destructor: ~App
	 * Description:
	 *   Automatically saves all users, stores, and merchandise
	 *   back to disk when the application exits.
	 */
	~App();

	/*
	 * Function: run
	 * Description:
	 *   Main application loop. Handles:
	 *     - Authentication menus
	 *     - Role-based user interaction
	 *     - Store navigation
	 *     - Purchasing and inventory management
	 */
	void run();

private:
	User* currUser; // Currently logged in user 
	Store* currStore; // Currently selected store
	vector<unique_ptr<User>> users; // All users
	vector<unique_ptr<Store>> stores; // All stores
};
