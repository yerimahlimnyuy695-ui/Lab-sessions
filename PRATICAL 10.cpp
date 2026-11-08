#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    double mark1;
    double mark2;
    double mark3;
};

double average(double a, double b, double c) {
    return (a + b + c) / 3.0;
}
char grade(double avg) {
    if (avg >= 70)
        return 'B';
    else if (avg >= 60)
        return 'C';
    else if (avg >= 50)
        return 'D';
    else
        return 'F';
}
bool isPass(double avg) {
    return avg >= 50;
}

void printReport(const Student& s) {
    double avg = average(s.mark1, s.mark2, s.mark3);
    cout << "\n===== STUDENT REPORT =====" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Average: " << avg << endl;
    cout << "Grade: " << grade(avg) << endl;
    if (isPass(avg))
        cout << "Result: PASS" << endl;
    else
        cout << "Result: FAIL" << endl;
}

int main() {
    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter first mark: ";
    cin >> student.mark1;
    cout << "Enter second mark: ";
    cin >> student.mark2;
    cout << "Enter third mark: ";
    cin >> student.mark3;
    printReport(student);

    return 0;
}
