#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/*
 This program simulates a betting game where the user wagers on rolling doubles with two dice.
 Amare Johnson
 */

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // User's bank
    double bank = 500.00;
    double wager;

    // Welcome message
    cout << "Welcome to the Dice Roll Doubles Game!" << endl;
    cout << "You have a starting bank of $" << fixed << setprecision(2) << bank << "." << endl;

    // Wager from the user
    cout << "How much would you like to wager? $";
    cin >> wager;

    // Input checking
    if (wager < 0) 
    {
        cout << "Error: You cannot wager a negative amount." << endl;
        return 1; // End the program
    }
    if (wager > bank) 
    {
        cout << "Error: You cannot wager more than your current bank of $" << fixed << setprecision(2) << bank << "." << endl;
        return 1; // End the program
    }

    // Simulate rolling two dice
    int die1 = rand() % 6 + 1; // Roll first die
    int die2 = rand() % 6 + 1; // Roll second die

    // Display the rolled numbers
    cout << "You rolled a " << die1 << " and a " << die2 << "." << endl;

    // Check for doubles
    if (die1 == die2) 
    {
        cout << "Congratulations! You rolled doubles!" << endl;
        bank += wager; // Increase bank by the wager amount
    } else 
    
    {
        cout << "Sorry, you did not roll doubles." << endl;
        bank -= wager; // Decrease bank by the wager amount
    }

    // Echo the wager back to the user
    cout << "You wagered: $" << fixed << setprecision(2) << wager << "." << endl;
    cout << "Your new bank balance is: $" << fixed << setprecision(2) << bank << "." << endl;

    return 0; // Exit the program
}
