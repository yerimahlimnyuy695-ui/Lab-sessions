#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<int> marks = {45, 78, 90, 32, 67, 88, 54, 73};
    const int passMark = 50;

    int total = 0;
    int minimum = marks[0];
    int maximum = marks[0];
    int passCount = 0;

    for (int mark : marks) {
        total += mark;

        if (mark < minimum) {
            minimum = mark;
        }

        if (mark > maximum) {
            maximum = mark;
        }

        if (mark >= passMark) {
            passCount++;
        }
    }

    double average = static_cast<double>(total) / marks.size();

    cout << fixed << setprecision(3);
    cout << "\nCLASS RESULTS\n";
    cout << "Total marks: " << total << '\n';
    cout << "Average mark: " << average << '\n';
    cout << "Minimum mark: " << minimum << '\n';
    cout << "Maximum mark: " << maximum << '\n';
    cout << "Number of passes: " << passCount << '\n';

    cout << "\nFAILING STUDENTS\n";
    bool anyFailure = false;

    for (int i = 0; i < static_cast<int>(marks.size()); i++) {
        if (marks[i] < passMark) {
            cout << "Index " << i << " - Mark: " << marks[i] << '\n';
            anyFailure = true;
        }
    }

    if (!anyFailure) {
        cout << "There are no failing students.\n";
    }

    int searchMark;
    bool found = false;

    cout << "\nEnter a mark to search for: ";
    cin >> searchMark;

    for (int i = 0; i < static_cast<int>(marks.size()); i++) {
        if (marks[i] == searchMark) {
            cout << "Mark " << searchMark << " found at index " << i << ".\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Mark " << searchMark << " was not found.\n";
    }

    int extraCount;
    cout << "\nHow many additional marks do you want to add? ";
    cin >> extraCount;

    if (extraCount < 0) {
        cout << "The number of additional marks cannot be negative.\n";
    } else {
        for (int i = 0; i < extraCount; i++) {
            int newMark;
            cout << "Enter additional mark " << i + 1 << ": ";
            cin >> newMark;

            if (newMark >= 0 && newMark <= 100) {
                marks.push_back(newMark);
            } else {
                cout << "Invalid mark. It was not added.\n";
            }
        }

        cout << "\nUpdated list of marks:\n";
        for (int mark : marks) {
            cout << mark << " ";
        }
        cout << '\n';
    }

    return 0;
}
