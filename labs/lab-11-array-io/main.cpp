/*
 * Lab 11: Reading Input & Arrays
 * 
 * Purpose: This program reads integers from an input file, stores them in an array,
 * performs calculations (sum, max, min, average), and writes results to an output file.
 * 
 * Written by Amare Johnson
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Maximum size of the array
const int MAX_SIZE = 50;

int main() {
    // Declare variables
    int numbers[MAX_SIZE];  // Array to store numbers from input file
    int count = 0;         // Counter for number of values read
    int sum = 0;           // Sum of all numbers
    int max, min;          // Maximum and minimum values
    double average;        // Average of all numbers
    
    // Open input file
    ifstream inFile("input.txt");
    
    // Check if input file opened successfully
    if (!inFile) {
        cout << "Error opening input file" << endl;
        return 1;
    }
    
    // Read numbers from file into array
    while (inFile >> numbers[count] && count < MAX_SIZE) {
        count++;
    }
    
    // Close input file
    inFile.close();
    
    // Initialize max and min with first element
    max = min = numbers[0];
    
    // Calculate sum, find max and min
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    // Calculate average
    average = static_cast<double>(sum) / count;
    
    // Open output file
    ofstream outFile("output.txt");
    
    // Check if output file opened successfully
    if (!outFile) {
        cout << "Error opening output file" << endl;
        return 1;
    }
    
    // Write results to output file
    outFile << "Sum: " << sum << endl;
    outFile << "Maximum value: " << max << endl;
    outFile << "Minimum value: " << min << endl;
    outFile << "Average: " << fixed << setprecision(2) << average << endl;
    
    // Close output file
    outFile.close();
    
    cout << "Processing complete. Check output.txt for results." << endl;
    
    return 0;
}
