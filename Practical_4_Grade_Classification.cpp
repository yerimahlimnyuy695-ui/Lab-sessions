#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double mark;

        cout << "\nEnter a mark from 0 to 100: ";
        cin >> mark;

        // Reject marks outside the permitted range.
        if (mark < 0 || mark > 100) {
            cout << "Invalid mark. Enter a value from 0 to 100.\n";
        } else {
            // Assign a grade according to the mark.
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

            // A mark of 50 or more is a pass.
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

/*
EXPLANATION
- do...while executes the grading process at least once and repeats while
  the user enters y or Y.
- if / else if selects the correct grade range.
- The separate pass/fail condition uses 50 as the pass mark.
- The first condition checks that the mark is between 0 and 100.

TESTS
100 -> A, PASS
80  -> A, PASS
79  -> B, PASS
69  -> C, PASS
59  -> D, PASS
49  -> F, FAIL
101 -> Invalid mark
*/
