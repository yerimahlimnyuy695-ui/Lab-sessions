#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    cout << "Calling factorial(" << n << ")\n";

    if (n == 0 || n == 1) {
        cout << "Base case: returning 1\n";
        return 1;
    }

    unsigned long long result = n * factorial(n - 1);
    cout << "Returning from factorial(" << n << "): " << result << '\n';
    return result;
}

int recursiveSum(int n) {
    if (n <= 0) return 0;
    return n + recursiveSum(n - 1);
}

int iterativeSum(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) total += i;
    return total;
}

int main() {
    int n;
    cout << "Enter factorial number (0-20): ";
    cin >> n;

    if (!cin || n < 0 || n > 20) {
        cout << "Enter a whole number from 0 to 20.\n";
        return 0;
    }

    cout << "\nFACTORIAL CALL TRACE\n";
    cout << n << "! = " << factorial(n) << '\n';

    int sumNumber;
    cout << "\nEnter number for sum (0-100): ";
    cin >> sumNumber;

    if (!cin || sumNumber < 0 || sumNumber > 100) {
        cout << "Enter a whole number from 0 to 100.\n";
        return 0;
    }

    cout << "Recursive sum: " << recursiveSum(sumNumber) << '\n';
    cout << "Iterative sum: " << iterativeSum(sumNumber) << '\n';
    return 0;
}
