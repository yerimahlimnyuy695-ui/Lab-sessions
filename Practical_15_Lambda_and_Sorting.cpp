#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double mark1, mark2, mark3;
    double average;
};

int main() {
    const double passThreshold = 50.0;

    vector<Student> students = {
        {101, "Amina", 80, 85, 90, 0},
        {102, "Brian", 60, 70, 65, 0},
        {103, "Carla", 90, 90, 90, 0},
        {104, "David", 45, 50, 55, 0},
        {105, "Esther", 90, 90, 90, 0},
        {106, "Frank", 40, 45, 48, 0}
    };

    for (Student& student : students) {
        student.average = (student.mark1 + student.mark2 + student.mark3) / 3.0;
    }

    cout << fixed << setprecision(2);
    cout << "ORIGINAL ORDER\n";
    for (const Student& student : students) {
        cout << student.id << " " << student.name << " " << student.average << '\n';
    }

    // Descending average; lower ID comes first when averages are equal.
    sort(students.begin(), students.end(),
         [](const Student& first, const Student& second) {
             if (first.average == second.average)
                 return first.id < second.id;
             return first.average > second.average;
         });

    cout << "\nSORTED ORDER\n";
    for (const Student& student : students) {
        cout << student.id << " " << student.name << " " << student.average << '\n';
    }

    int passCount = count_if(
        students.begin(), students.end(),
        [passThreshold](const Student& student) {
            return student.average >= passThreshold;
        }
    );

    cout << "\nStudents with average at least " << passThreshold
         << ": " << passCount << '\n';

    cout << "\nTOP THREE STUDENTS\n";
    int limit = min(3, static_cast<int>(students.size()));
    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". " << students[i].name
             << " - " << students[i].average << '\n';
    }

    return 0;
}
