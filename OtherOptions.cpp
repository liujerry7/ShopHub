#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include "Customer.h"
#include "OtherOptions.h"
#include "Merchandise.h"




void addCustomer(vector<Customer>& customers) {
    string name;
    double balance;

    cout << "Enter new customer's name: ";
    getline(cin >> ws, name);

    cout << "Enter initial balance- ";
    cin >> balance;

    customers.push_back(Customer(name, balance));

    cout << "New Customer Added!\n\n";
    cout << "Name\t\tBalance";
    cout << setfill('-') << setw(100);
    cout << name << "\t\t" << balance;  
}

void addMerchandiseToDepartment (vector<pair<string, double>>& department) {
    string itemName;
    double itemPrice;

    cout << "Enter item: ";
    getline(cin >> ws, itemName);
    cout << "\t\t\t Price: " << endl;
    cin >> itemPrice;
    cout << "\n\n" << endl;

    department.push_back(itemName, itemPrice);

    cout << "New Item Added:\n\n";
    cout << "Item\t\tPrice";
    cout << setfill('-') << setw(100);
    cout << itemName << "\t\t" << itemPrice;
    cout << "\n\n" << endl;



}

void makePurchase(vector<Customer>& customers, vector<pair<string, double>>& department) {
    if (customers.empty()) {
        throw out_of_range("No customers added.\n");
        return;
    }

    //1st choose a customer
    for (int i = 0; i < customers.size(); i++) {
        cout << i + 1 << ")" << customers[i].getName() << endl;
    }

    int customerChosen;
    cin >> customerChosen;
    int customerIndex = customerChosen - 1; //(since menu displays index++)

    if (customerChosen < 0 || customerChosen >= customers.size()) {
        throw out_of_range("Customer input invalid.\n");
        return;
    }


//2nd Choose the Merchandise
    bool running = true;
    while (running) {

        int browsing = 1;
        vector<pair<string, double>> cart; //store selected items

        if (browsing == 1) {
            cout << setfill(' ') << setw(50) << "Main Menu";
            cout << "Choose a department- \n\n";
            cout << "1) Apparel\n";
            cout << "2) Electronics\n";
            cout << "3) Cancel and go back\n\n";
        }
        else if (browsing > 1) {
            cout << setfill(' ') << setw(50) << "Main Menu";
            cout << "Choose a department- \n\n";
            cout << "1) Apparel\n";
            cout << "2) Electronics\n";
            cout << "3) Done and checkout\n";
            cout << "4) Cancel and go back\n\n";
        }
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            department = apparel; 
            void displayMerchandise(department);
            
            char itemChoice;
            cout << "Choose an item to add to your cart: \n\n\n"
            cout << "press 0 - Go back";

            if (transaction > 1) {
                cout << "\t\t\t" << "press C - checkout";
            }
            cin >> itemChoice;

            if (itemChoice == 0) {return;}

            else if (itemChoice == C) { choice = 3; break;}
            
            else {
                itemIndex = itemChoice - 1;
                if (itemIndex < 0 || itemIndex > department.size()) {
                    cout << "Invalid item";
                }
                //add item to cart
                else  {
                    cart.push_back(department[itemIndex]);
                    cout << "Added to cart";
                    cout << "Item" << "\t\t\t" << "Price" << "\n";
                    cout << setw('-') << setfill(100) << endl;
                    cout << cart[0].first << "\t\t\t" << cart[0].second;

                }

            }
            return;}

        else if (choice == 2) {
            department = electronics; 
            void displayMerchandise(department);
             char itemChoice;
            cout << "Choose an item to add to your cart: \n\n\n"
            cout << "press 0 - Go back";

            if (transaction > 1) {
                cout << "\t\t\t" << "press C - checkout";
            }
            cin >> itemChoice;

            if (itemChoice == 0) {return;}

            else if (itemChoice == C) { choice = 3; break;}
            
            else {
                itemIndex = itemChoice - 1;
                if (itemIndex < 0 || itemIndex > department.size()) {
                    cout << "Invalid item";
                }
                //add item to cart
                else  {
                    cart.push_back(department[itemIndex]);
                    cout << "Added to cart";
                    cout << "Item" << "\t\t\t" << "Price" << "\n";
                    cout << setw('-') << setfill(100) << endl;
                    cout << cart[0].first << "\t\t\t" << cart[0].second;
                    
                }

            }
            
            return;}

        else if (choice == 3 || choice == 4) { 
            if (transaction == 1) {
                running = false;
                continue;
            }

            if (transaction > 1) {
            if (cart.empty()) {
                throw logic_error("No items added to cart. Please try again.");
                break;
            }

            else {
                for (i = 0; i < cart.size(); i++ ) {
                double runningTotal += i;
                }

                cout << "Are you ready to checkout?\n";
                cout << "Item\t\t\tPrice"
                cout << setfill(100) << endl;
                for (i = 0; i < cart.size(); i++) {
                    cout << cart[i].first << "\t\t\t" << "$"
                        << cart[i].second << "\n\n" << endl;
                }
                cout << "Amount due" << "\t\t\t" << runningTotal;
            
                cout << "Confirm Purchase?" << "\n\n";
                cout << "(1/Y) for yes" << "\n";
                cout << "(2/N) for no" << "\n";

                char confirmPurchase;
                cin >> confirmPurchase;
                if (confirmPurchase == 1 || confirmPurchase == Y) {

                    for (i = 0; i < cart.size(); i++) {
                        customers[customerIndex].addCharge(cart[i].second);
                        customers[customerIndex].addPurchase(cart[i].first);
                    }
                    transaction++;

                    cout << "Your checkout is complete!" << "\n\n\n";
                    cout << "Customer Details: " << "\n\n";
                    cout << "Name " << "\t\t\t" << "Balance" << "\n";
                    cout << setw('-') << setfill(100) << endl;
                    cout << customers[customerIndex].first << "\t\t\t"
                        << customers[customerIndex].second << endl;

                }

                else if (confirmPurchase == 2 || confirmPurchase == N) {
                    cout << "Discarding Purchase";
                }
            }
        }

        }
        else if (choice == 0) { 
            running = false;
            return; }

        else { throw logic_error("No option selected. Please try again.") };

    }

}

void displayMerchandise(vector<pair<string, double>>& department) {
   
    cout << "Item\t\t\tPrice";
    cout << setfill('-') << setw(100);
    for (int i = 0; i < department.size(); i++) {
        cout << i+1 << ")" << department[i].first << "\t\t\t"
            << "$" << department[i].second;
    }

    
}

void catch(exception& e) {
    cout << e.what();
}