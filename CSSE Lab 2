/*
 * Program: Searching and Sorting Algorithm Implementation
 * Purpose: This program demonstrates the use of linear search and selection sort algorithms.
 *          It allows users to input 10 numbers, searches for negative numbers using linear search,
 *          optionally sorts the array using selection sort, and displays relevant statistics.
 * 
 * Functionality:
 * - Takes 10 numbers as input
 * - Performs linear search to find negative numbers
 * - Optionally sorts the array using selection sort
 * - Displays search and sort statistics
 * 
 * Written by Amare Johnson
 */

#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int arr[], int size, int& exchanges);
bool linearSearch(int arr[], int size, int& comparisons);
void displayArray(const int arr[], int size);

int main() {
    const int SIZE = 10;
    int numbers[SIZE];
    int searchComparisons = 0;
    int sortExchanges = 0;
    char sortChoice;
    
    // Input phase
    cout << "Enter 10 numbers:\n";
    for(int i = 0; i < SIZE; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Linear search for negative numbers
    bool hasNegative = linearSearch(numbers, SIZE, searchComparisons);
    
    // Ask user if they want to sort the array
    cout << "\nDo you want to sort the array? (y/n): ";
    cin >> sortChoice;
    
    // Sort if user wants to
    if(sortChoice == 'y' || sortChoice == 'Y') {
        selectionSort(numbers, SIZE, sortExchanges);
    }
    
    // Display results
    cout << "\nFinal Array: ";
    displayArray(numbers, SIZE);
    
    cout << "\nStatistics:" << endl;
    cout << "Number of elements checked in search: " << searchComparisons << endl;
    cout << "Number of exchanges made in sorting: " << sortExchanges << endl;
    cout << "Array contains negative numbers: " << (hasNegative ? "Yes" : "No") << endl;
    
    return 0;
}

// Function to perform linear search for negative numbers
bool linearSearch(int arr[], int size, int& comparisons) {
    comparisons = 0;
    for(int i = 0; i < size; i++) {
        comparisons++;
        if(arr[i] < 0) {
            return true;
        }
    }
    return false;
}

// Function to perform selection sort
void selectionSort(int arr[], int size, int& exchanges) {
    exchanges = 0;
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted portion
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap if minimum element is not already in position
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            exchanges++;
        }
    }
}

// Function to display array contents
void displayArray(const int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
