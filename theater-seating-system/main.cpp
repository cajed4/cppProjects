#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int ROWS = 15;
const int COLS = 30;

// Function prototypes
vector<double> readPricesAndSeats(const string& filename, vector<vector<char>>& seats);
void saveSeats(const vector<vector<char>>& seats, const vector<double>& prices, const string& filename);
void displaySeatingChart(const vector<vector<char>>& seats);
void purchaseTicket(vector<vector<char>>& seats, const vector<double>& prices, double& totalSales, int& ticketsSold);
void displayTotalSales(double totalSales);
void displayTotalTicketsSold(int ticketsSold);
void displaySeatsAvailable(const vector<vector<char>>& seats);
void displayTotalAvailableSeats(const vector<vector<char>>& seats);
void displayMenu();

int main() {
    vector<vector<char>> seats(ROWS, vector<char>(COLS, '#')); // Initialize seating chart
    vector<double> prices = readPricesAndSeats("seats.txt", seats);

    // Default prices if the file is not available
    if (prices.empty()) 
    {
        for (double price = 10.0; price <= 38.0; price += 2.0) 
        {
            prices.push_back(price);
        }
    }

    double totalSales = 0;
    int ticketsSold = 0;
    int choice;

    do 
    
    {
        displayMenu();
        cin >> choice;

        switch (choice) 
        
        {
            case 1:
                purchaseTicket(seats, prices, totalSales, ticketsSold);
                saveSeats(seats, prices, "seats.txt"); // Save after purchase
                break;
            case 2:
                displayTotalSales(totalSales);
                break;
            case 3:
                displayTotalTicketsSold(ticketsSold);
                break;
            case 4:
                displaySeatsAvailable(seats);
                break;
            case 5:
                displayTotalAvailableSeats(seats);
                break;
            case 6:
                displaySeatingChart(seats);
                break;
            case 7:
                saveSeats(seats, prices, "seats.txt"); // Save before exit
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Function to read prices and seating chart from a file
vector<double> readPricesAndSeats(const string& filename, vector<vector<char>>& seats) 

{
    vector<double> prices;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error: Unable to open " << filename << endl;
        return prices; // Return empty prices
    }

    // Read prices from the first line
    if (getline(file, line)) 
    
    {
        double price;
        istringstream iss(line);
        while (iss >> price) {
            prices.push_back(price);
        }
    }

    // Read seating chart from the subsequent lines
    for (int i = 0; i < ROWS && getline(file, line); i++) 
    
    {
        for (int j = 0; j < COLS && j < line.length(); j++) 
        
        {
            seats[i][j] = line[j]; // Read the seating chart directly
        }
    }

    file.close();
    return prices;
}

// Function to save seating chart and prices to a file
void saveSeats(const vector<vector<char>>& seats, const vector<double>& prices, const string& filename) 

{
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Unable to save to " << filename << endl;
        return;
    }

    // Save prices to the first line
    for (const auto& price : prices) 
    
    {
        file << price << ' ';
    }
    file << endl;

    // Save seating chart
    for (const auto& row : seats) {
        for (const auto& seat : row) 
        
        {
            file << seat;
        }
        file << endl;
    }

    file.close();
}

// Function to display the seating chart
void displaySeatingChart(const vector<vector<char>>& seats) 

{
    cout << "\nSeating Chart:\n";
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            cout << seat << ' ';
        }
        cout << endl;
    }
}

// Function to purchase a ticket
void purchaseTicket(vector<vector<char>>& seats, const vector<double>& prices, double& totalSales, int& ticketsSold) 

{
    int row, seat;
    cout << "Enter row number (0-14): ";
    cin >> row;
    cout << "Enter seat number (0-29): ";
    cin >> seat;

    // Validate row and seat number
    if (row < 0 || row >= ROWS || seat < 0 || seat >= COLS) 
    {
        cout << "Invalid row or seat number.\n";
        return;
    }

    // Check if seat is available
    if (seats[row][seat] == '*') 
    {
        cout << "Seat already taken. Choose another seat.\n";
        return;
    }

    // Update seating chart and sales data
    seats[row][seat] = '*';
    double ticketPrice = prices[row]; // Assuming prices are per row
    totalSales += ticketPrice;
    ticketsSold++;

    // Display ticket purchase confirmation
    cout << "Ticket purchased! Total price: $" << fixed << setprecision(2) << ticketPrice << endl;
}

// Function to display total sales
void displayTotalSales(double totalSales) 
{
    cout << "Total dollar value of tickets sold: $" << fixed << setprecision(2) << totalSales << endl;
}

// Function to display total tickets sold
void displayTotalTicketsSold(int ticketsSold) 
{
    cout << "Total number of tickets sold: " << ticketsSold << endl;
}

// Function to display seats available in each row
void displaySeatsAvailable(const vector<vector<char>>& seats) 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        int available = 0;
        for (int j = 0; j < COLS; ++j) 
        {
            if (seats[i][j] == '#') 
            {
                available++;
            }
        }
        cout << "Row " << i << ": " << available << " seats available\n";
    }
}

// Function to display total available seats
void displayTotalAvailableSeats(const vector<vector<char>>& seats) 

{
    int totalAvailable = 0;
    for (const auto& row : seats) 
    
    {
        for (const auto& seat : row) 
        
        {
            if (seat == '#') 
            {
                totalAvailable++;
            }
        }
    }
    cout << "Total seats available: " << totalAvailable << endl;
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Purchase tickets\n";
    cout << "2. Display total dollar value of tickets sold\n";
    cout << "3. Display total number of tickets sold\n";
    cout << "4. Display number of seats available in each row\n";
    cout << "5. Display number of seats available in the entire auditorium\n";
    cout << "6. Display current seating chart\n";
    cout << "7. Exit the system\n";
    cout << "Choose an option: ";
}
