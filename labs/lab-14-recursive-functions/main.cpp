
/*
Write two recursive functions: 
Recursive Power Function
Write a function that uses recursion to raise a number to a power. The function should accept two arguments: the number to be raised and the exponent.
Assume that the exponent is a nonnegative integer. 

Recursive Multiplication
Write a recursive function that accepts two arguments into the parameters x and y . The function should return the value of x times y . 
Remember, multiplication can be performed as repeated addition: 7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4

Done by Amare Johnson
*/


#include <iostream>
using namespace std;

// Recursive function to calculate base raised to exponent
int power(int base, int exponent) {
    // Base case: anything raised to the power of 0 is 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive case: base^exponent = base * base^(exponent-1)
    else {
        return base * power(base, exponent - 1);
    }
}

// Recursive function to multiply x and y using repeated addition
int multiply(int x, int y) {
    // Base cases
    if (y == 0) {
        return 0;
    }
    else if (y == 1) {
        return x;
    }
    // Recursive case: x * y = x + x * (y-1)
    else {
        return x + multiply(x, y - 1);
    }
}

int main() {
    // Testing the power function
    int base = 2;
    int exponent = 3;
    cout << "Power Function Test:" << endl;
    cout << base << " raised to the power " << exponent 
         << " is " << power(base, exponent) << endl;
    
    // Testing the multiply function
    int x = 4;
    int y = 3;
    cout << "\nMultiplication Function Test:" << endl;
    cout << x << " multiplied by " << y 
         << " is " << multiply(x, y) << endl;
    
    return 0;
}
