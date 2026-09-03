
/*
 * Weather Data Management
 * This program stores and analyzes weather data for a full year.
 * It collects monthly weather data including rainfall, temperatures,
 * and calculates various statistics including averages and extremes.
 * 
 * Written by Amare Johnson
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold weather data for a single month
struct WeatherData {
    string monthName;
    double totalRainfall;
    double highTemp;
    double lowTemp;
    double avgTemp;
};

// Function prototypes
void inputWeatherData(WeatherData& month);
void calculateYearlyStats(const WeatherData months[], int size);
bool isValidTemperature(double temp);

int main() {
    const int MONTHS = 12;
    WeatherData year[MONTHS];
    
    // Array of month names for easy reference
    string monthNames[MONTHS] = {"January", "February", "March", "April", "May", 
                                "June", "July", "August", "September", "October", 
                                "November", "December"};
    
    // Get data for each month
    cout << "Enter weather data for each month:\n\n";
    for (int i = 0; i < MONTHS; i++) {
        cout << "Enter data for " << monthNames[i] << ":\n";
        year[i].monthName = monthNames[i];
        inputWeatherData(year[i]);
        cout << endl;
    }
    
    // Calculate and display yearly statistics
    calculateYearlyStats(year, MONTHS);
    
    return 0;
}

// Function to input and validate weather data for a single month
void inputWeatherData(WeatherData& month) {
    double high, low;
    
    // Get rainfall data
    cout << "Total rainfall (inches): ";
    cin >> month.totalRainfall;
    
    // Get and validate temperature data
    do {
        cout << "High temperature (F): ";
        cin >> high;
        if (!isValidTemperature(high))
            cout << "Invalid temperature. Must be between -100 and 140 F.\n";
    } while (!isValidTemperature(high));
    
    do {
        cout << "Low temperature (F): ";
        cin >> low;
        if (!isValidTemperature(low))
            cout << "Invalid temperature. Must be between -100 and 140 F.\n";
        if (low > high)
            cout << "Low temperature cannot be higher than high temperature.\n";
    } while (!isValidTemperature(low) || low > high);
    
    month.highTemp = high;
    month.lowTemp = low;
    month.avgTemp = (high + low) / 2.0;
}

// Function to validate temperature range
bool isValidTemperature(double temp) {
    return (temp >= -100 && temp <= 140);
}

// Function to calculate and display yearly statistics
void calculateYearlyStats(const WeatherData months[], int size) {
    double totalRainfall = 0.0;
    double totalAvgTemp = 0.0;
    double highestTemp = -100.0;
    double lowestTemp = 140.0;
    string highestMonth, lowestMonth;
    
    // Calculate statistics
    for (int i = 0; i < size; i++) {
        totalRainfall += months[i].totalRainfall;
        totalAvgTemp += months[i].avgTemp;
        
        if (months[i].highTemp > highestTemp) {
            highestTemp = months[i].highTemp;
            highestMonth = months[i].monthName;
        }
        
        if (months[i].lowTemp < lowestTemp) {
            lowestTemp = months[i].lowTemp;
            lowestMonth = months[i].monthName;
        }
    }
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\nYearly Weather Summary:\n";
    cout << "------------------------\n";
    cout << "Average monthly rainfall: " << totalRainfall / size << " inches\n";
    cout << "Total yearly rainfall: " << totalRainfall << " inches\n";
    cout << "Highest temperature: " << highestTemp << "F (" << highestMonth << ")\n";
    cout << "Lowest temperature: " << lowestTemp << "F (" << lowestMonth << ")\n";
    cout << "Average temperature for the year: " << totalAvgTemp / size << "F\n";
}


