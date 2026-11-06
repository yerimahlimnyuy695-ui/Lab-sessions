#include <iostream>
using namespace std;

int main() {
    int number;
    int n;
    int sum = 0;

    // Part 1: multiplication table from 1 to 12.
    cout << "Enter a number for its multiplication table: ";
    cin >> number;

    cout << "\nMultiplication table of " << number << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << '\n';
    }

    // Part 2: sum all integers from 1 to n.
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

    // Part 3: print numbers from 1 to 30, skipping multiples of 3.
    cout << "\nNumbers from 1 to 30, excluding multiples of 3:\n";
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0) {
            continue; // Skip the rest of this loop cycle.
        }
        cout << i << " ";
    }
    cout << '\n';

    // Part 4: find the first number divisible by both 5 and 7.
    cout << "\nFirst common multiple of 5 and 7:\n";
    for (int i = 1; i <= 100; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            cout << i << '\n';
            break; // Stop at the first matching number.
        }
    }

    // Extra challenge: multiplication table using while.
    cout << "\nMultiplication table using while:\n";
    int multiplier = 1;
    while (multiplier <= 12) {
        cout << number << " x " << multiplier
             << " = " << number * multiplier << '\n';
        multiplier++;
    }

    return 0;
}

/*
EXPLANATION
- for repeats a block while its condition is true.
- i++ increases the counter by one.
- sum += i adds the current number to sum.
- % calculates the remainder. A remainder of zero means divisible.
- continue skips the current loop cycle.
- break exits the loop completely.
- while repeats as long as its condition remains true.

TEST
For n = 10, the sum is 55.
The first number divisible by both 5 and 7 is 35.
*/
