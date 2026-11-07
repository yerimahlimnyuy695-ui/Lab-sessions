#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum class Status {
    PASS,
    FAIL
};

struct Student {
    int id;
    string name;
    double mark1;
    double mark2;
    double mark3;
    double average;
    Status status;
};

int main() {
    const double passMark = 50.0;

    vector<Student> students = {
        {101, "Amina", 60, 70, 80, 0, Status::FAIL},
        {102, "Brian", 40, 50, 45, 0, Status::FAIL},
        {103, "Carla", 50, 50, 50, 0, Status::FAIL},
        {104, "David", 90, 85, 95, 0, Status::FAIL},
        {105, "Esther", 35, 55, 60, 0, Status::FAIL}
    };

    for (Student &student : students) {
        student.average =
            (student.mark1 + student.mark2 + student.mark3) / 3.0;

        if (student.average >= passMark) {
            student.status = Status::PASS;
        } else {
            student.status = Status::FAIL;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nSTUDENT CLASS REPORT\n";
    cout << left << setw(10) << "ID"
         << setw(16) << "Name"
         << setw(12) << "Average"
         << "Status\n";
    cout << "------------------------------------------\n";

    for (const Student &student : students) {
        cout << left << setw(10) << student.id
             << setw(16) << student.name
             << setw(12) << student.average
             << (student.status == Status::PASS ? "PASS" : "FAIL")
             << '\n';
    }

    int searchID;
    bool found = false;

    cout << "\nEnter the student ID to search for: ";
    cin >> searchID;

    for (const Student &student : students) {
        if (student.id == searchID) {
            cout << "Student found: " << student.name
                 << ", average: " << student.average
                 << ", status: "
                 << (student.status == Status::PASS ? "PASS" : "FAIL")
                 << '\n';
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No student with ID " << searchID << " was found.\n";
    }

    cout << "\nPASS MARK TEST\n";
    double testAverages[] = {49.99, 50.00};

    for (double value : testAverages) {
        cout << value << ": "
             << (value >= passMark ? "PASS" : "FAIL") << '\n';
    }


    sort(students.begin(), students.end(),
         [](const Student &first, const Student &second) {
             return first.average > second.average;
         });

    cout << "\nSTUDENTS SORTED BY AVERAGE (HIGHEST TO LOWEST)\n";
    for (const Student &student : students) {
        cout << student.name << " - " << student.average << '\n';
    }

    return 0;
}
