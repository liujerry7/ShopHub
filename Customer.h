//Write into program
//Users can
//1. Add new merchandise to the menu.
//2. Access and display the menu.
//3. Add customer objects (with balance) to customer class.
//4. Make purchases and process refunds.

#include <string>
#include <vector>
using namespace std;

//customer class
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer {
    private:
    string name;
    double balance;
    vector<pair<string, double>> purchases;

    public:

    //customer constructors
    Customer(); //default constructor
    Customer(const string& name, double initialBalance);

    //getter functions
    string getName() const;
    double getBalance() const;

    //getter for customer purchases
    vector<pair<string, double>> getPurchases() const;

    //setter functions
    void setname(const string& newName);
    void setBalance(double newBalance);

    //User Functions
    void addCharge(double price);
    void processRefund(double price);
   
    void addPurchase(const string& itemName, double price);
};



#endif