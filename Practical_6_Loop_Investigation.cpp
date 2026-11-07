#include <iostream>
using namespace std;

int main() {
    int number;
    int n;
    int sum = 0;

    
    cout << "Enter a number for its multiplication table: ";
    cin >> number;

    cout << "\nMultiplication table of " << number << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << '\n';
    }

    
    cout << "\nEnter n to calculate the sum from 1 to n: ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer.\n";
    } else {
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        cout << "Sum from 1 to " << n << " = " << sum << '\n';
    }

    
    cout << "\nNumbers from 1 to 30, excluding multiples of 3:\n";
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0) {
            continue; 
        }
        cout << i << " ";
    }
    cout << '\n';

    
    cout << "\nFirst common multiple of 5 and 7:\n";
    for (int i = 1; i <= 100; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            cout << i << '\n';
            break; 
        }
    }

    
    cout << "\nMultiplication table using while:\n";
    int multiplier = 1;
    while (multiplier <= 12) {
        cout << number << " x " << multiplier
             << " = " << number * multiplier << '\n';
        multiplier++;
    }

    return 0;
}


