#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double mark;

        cout << "\nEnter a mark from 0 to 100: ";
        cin >> mark;

        
        if (mark < 0 || mark > 100) {
            cout << "Invalid mark. Enter a value from 0 to 100.\n";
        } else {
           
            if (mark >= 80) {
                cout << "Grade: A\n";
            } else if (mark >= 70) {
                cout << "Grade: B\n";
            } else if (mark >= 60) {
                cout << "Grade: C\n";
            } else if (mark >= 50) {
                cout << "Grade: D\n";
            } else {
                cout << "Grade: F\n";
            }

            if (mark >= 50) {
                cout << "Result: PASS\n";
            } else {
                cout << "Result: FAIL\n";
            }
        }

        cout << "\nDo you want to enter another mark? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended.\n";
    return 0;
}

