/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
using namespace std;

//create a class that tracks refunds and updates account balances

    void ProcessRefund(double b, string m, double p)
    {
        double balance = b;
        double price = p;
        string merchandise = m;
    //check if value is greater than zero
    //error message if value is less than zero
    
    cout << "Your current balance: " << balance << "\n\n";
        cout << "You chose Process Refund";
        cout << " for\n\n";
        cout << setfill(' ') << "Item" << setw(35) << "Price\n";
        cout << setfill('-') << setw(100) << "|\n";
        
       
        cout << "(photo)" << merchandise << "\t\t" << price << "\n\n";
        try {
            if (price <= 0) {
                
                throw invalid_argument("Product has no value.\n\n\n");
            } else {
                balance += price;
            }
        }
        
        catch (const exception& e) {
            cout << "Exception thrown: " << e.what() << "\n";
        }
        cout << "Your balance has increased $" << price << "\n";
        cout << "Your updated balance: " << "$" << balance << "\n\n";
    }

int main()

{
    double b = 3420.34;
    
    vector<pair<string, double>> Tops{ {"Pink Blouse", 42.25},
            {"Topaz Spaghetti Strap", 31.60} }; 

    ProcessRefund(b, Tops[0].first, Tops[0].second);
    
    

    return 0;
}