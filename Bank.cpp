#include <iostream>

using namespace std;

int main()
{
    double amount = 0.00;
    bool decision;  //Keeps track if the user wants to repeat
    int hundreds, fifties, twenties, tens, fives, ones;
    int quarters, dimes, nickels, pennies;

    while (1) {
        //Make sure everything is set to 0 for each loop
        decision = 0;
        hundreds = fifties = twenties = tens = fives = ones = 0;
        quarters = dimes = nickels = pennies = 0;
        //Ensure amount is between 0.00 and 100.00
        while (1) {
            cout << "Please enter a monetary amount between 0.00 and 100.00:  " << endl;
            cin >> amount;
            
            if (amount >= 0.00 && amount <= 100.00) {
                break;
            }
            else {
                cout << "Amount entered outside of accepted range" << endl;
            }
        }
        //Have to account for doubles being slightly off
        amount *= 100;
        if (amount - (int)amount > 0.9999) {
            amount++;
        }
        //Go through and get # of each bill
        while (1) {
            if (amount == (100.0 * 100)) {
                hundreds = 1;
                break;
            }
            else {
                fifties = (int)amount / (50 * 100);
                amount -= ((double)fifties * 50 * 100);
                if (amount == 0) {
                    break;
                }
                twenties = (int)amount / (20 * 100);
                amount -= ((double)twenties * 20 * 100);
                if (amount == 0) {
                    break;
                }
                tens = (int)amount / (10 * 100);
                amount -= ((double)tens * 10 * 100);
                if (amount == 0) {
                    break;
                }
                fives = (int)amount / (5 * 100);
                amount -= ((double)fives * 5 * 100);
                if (amount == 0) {
                    break;
                }
                ones = (int)amount / 100;
                amount -= ((double)ones * 100);
                if (amount == 0) {
                    break;
                }


                quarters = (int)amount / 25;
                amount -= ((double)quarters * 25);
                if ((int)amount == 0) {
                    break;
                }
                dimes = (int)amount / 10;
                amount -= ((double)dimes * 10);
                if ((int)amount == 0) {
                    break;
                }
                nickels = (int)amount / 5;
                amount -= ((double)nickels * 5);
                if ((int)amount == 0) {
                    break;
                }
                pennies = (int)amount;
                amount -= pennies;
                if ((int)amount == 0) {
                    break;
                }
                //Error if this gets reached
                cout << "An error in counting has occurred" << endl;
                break;
            }

        }
        //Output number of each bill
        cout << "Hundreds:  " << hundreds << endl;
        cout << "Fifties:  " << fifties << endl;
        cout << "Twenties:  " << twenties << endl;
        cout << "Tens:  " << tens << endl;
        cout << "Fives:  " << fives << endl;
        cout << "Ones:  " << ones << endl;
        cout << "Quarters:  " << quarters << endl;
        cout << "Dimes:  " << dimes << endl;
        cout << "Nickels:  " << nickels << endl;
        cout << "Pennies:  " << pennies << endl;

        cout << "\nWould you like to enter another amount? Enter 0 for no, 1 for yes:  " << endl;
        cin >> decision;
        if (decision == 0) {
            break;
        }
    }
    return 0;
}
