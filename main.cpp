#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class ClassStatus {
    Pass,
    Fail
};

struct Student {
    int id{};
    string name;
    double marks[3]{};

    double average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    ClassStatus status() const {
        return average() >= 50.0 ? ClassStatus::Pass : ClassStatus::Fail;
    }
};

bool readInteger(const string& prompt, int& value) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) {
            return false;
        }

        stringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra)) {
            return true;
        }

        cout << "Invalid input. Please enter a whole number.\n";
    }
}

bool readMark(const string& prompt, double& mark) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) {
            return false;
        }

        stringstream input(line);
        char extra;
        if ((input >> mark) && !(input >> extra) &&
            isfinite(mark) && mark >= 0.0 && mark <= 100.0) {
            return true;
        }

        cout << "Invalid mark. Enter a number from 0 to 100.\n";
    }
}

bool readNonEmptyText(const string& prompt, string& value) {
    while (true) {
        cout << prompt;
        if (!getline(cin, value)) {
            return false;
        }

        if (value.find('|') != string::npos) {
            cout << "The | character is not allowed. Try again.\n";
        } else if (value.find_first_not_of(" \t") == string::npos) {
            cout << "This field cannot be empty. Try again.\n";
        } else {
            return true;
        }
    }
}

int findStudentIndex(const vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void printStudent(const Student& student) {
    cout << left << setw(10) << student.id
         << setw(24) << student.name
         << right << fixed << setprecision(2)
         << setw(10) << student.marks[0]
         << setw(10) << student.marks[1]
         << setw(10) << student.marks[2]
         << setw(10) << student.average()
         << setw(10) << (student.status() == ClassStatus::Pass ? "Pass" : "Fail")
         << '\n';
}

void printTableHeading() {
    cout << left << setw(10) << "ID"
         << setw(24) << "Name"
         << right << setw(10) << "Mark 1"
         << setw(10) << "Mark 2"
         << setw(10) << "Mark 3"
         << setw(10) << "Average"
         << setw(10) << "Status" << '\n';
    cout << string(84, '-') << '\n';
}

void registerStudent(vector<Student>& students) {
    Student student;

    if (!readInteger("Enter student ID: ", student.id)) return;

    if (student.id <= 0) {
        cout << "Student ID must be a positive number.\n";
        return;
    }

    if (findStudentIndex(students, student.id) != -1) {
        cout << "A student with that ID already exists.\n";
        return;
    }

    if (!readNonEmptyText("Enter student name: ", student.name)) return;

    for (int i = 0; i < 3; ++i) {
        if (!readMark("Enter mark for subject " + to_string(i + 1) + ": ",
                      student.marks[i])) {
            return;
        }
    }

    students.push_back(student);
    cout << "Student registered successfully.\n";
}

void listStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "The class is empty. No student records to display.\n";
        return;
    }

    printTableHeading();
    for (const Student& student : students) {
        printStudent(student);
    }
}

void searchStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "The class is empty.\n";
        return;
    }

    int id;
    if (!readInteger("Enter student ID to search: ", id)) return;

    int index = findStudentIndex(students, id);
    if (index == -1) {
        cout << "No student found with ID " << id << ".\n";
        return;
    }

    printTableHeading();
    printStudent(students[static_cast<size_t>(index)]);
}

void updateMarks(vector<Student>& students) {
    if (students.empty()) {
        cout << "The class is empty. Register a student first.\n";
        return;
    }

    int id;
    if (!readInteger("Enter student ID: ", id)) return;

    int index = findStudentIndex(students, id);
    if (index == -1) {
        cout << "Student ID not found.\n";
        return;
    }

    Student& student = students[static_cast<size_t>(index)];
    cout << "Updating marks for " << student.name << ".\n";

    for (int i = 0; i < 3; ++i) {
        if (!readMark("Enter new mark for subject " + to_string(i + 1) + ": ",
                      student.marks[i])) {
            return;
        }
    }

    cout << "Marks updated successfully.\n";
}

void classStatistics(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No statistics available because the class is empty.\n";
        return;
    }

    double totalAverage = 0.0;
    int passCount = 0;
    int failCount = 0;

    for (const Student& student : students) {
        totalAverage += student.average();
        if (student.status() == ClassStatus::Pass) {
            ++passCount;
        } else {
            ++failCount;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nCLASS STATISTICS\n";
    cout << "Number of students: " << students.size() << '\n';
    cout << "Class average: " << totalAverage / students.size() << '\n';
    cout << "Students who passed: " << passCount << '\n';
    cout << "Students who failed: " << failCount << '\n';
}

void topStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "The class is empty. There is no top student.\n";
        return;
    }

    double highestAverage = max_element(
        students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.average() < b.average();
        })->average();

    const double tolerance = 0.000001;
    auto tiedStudents = [highestAverage, tolerance](const Student& student) {
        return fabs(student.average() - highestAverage) < tolerance;
    };

    cout << "Top student(s), average: " << fixed << setprecision(2)
         << highestAverage << '\n';
    printTableHeading();

    for (const Student& student : students) {
        if (tiedStudents(student)) {
            printStudent(student);
        }
    }
}

void passList(const vector<Student>& students) {
    auto hasPassed = [](const Student& student) {
        return student.status() == ClassStatus::Pass;
    };

    vector<Student> passedStudents;
    copy_if(students.begin(), students.end(), back_inserter(passedStudents), hasPassed);

    if (passedStudents.empty()) {
        cout << "There are no students on the pass list.\n";
        return;
    }

    sort(passedStudents.begin(), passedStudents.end(),
         [](const Student& a, const Student& b) {
             return a.average() > b.average();
         });

    cout << "PASS LIST (sorted by average, highest first)\n";
    printTableHeading();
    for (const Student& student : passedStudents) {
        printStudent(student);
    }
}

void saveRecords(const vector<Student>& students) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Warning: records could not be saved.\n";
        return;
    }

    file << setprecision(17);
    for (const Student& student : students) {
        file << student.id << '|'
             << student.name << '|'
             << student.marks[0] << '|'
             << student.marks[1] << '|'
             << student.marks[2] << '\n';
    }
    cout << "Records saved to students.txt.\n";
}

bool parseStudentLine(const string& line, Student& student) {
    stringstream input(line);
    string idText, name, mark1Text, mark2Text, mark3Text;

    if (!getline(input, idText, '|') ||
        !getline(input, name, '|') ||
        !getline(input, mark1Text, '|') ||
        !getline(input, mark2Text, '|') ||
        !getline(input, mark3Text)) {
        return false;
    }

    string extra;
    if (getline(input, extra, '|')) {
        return false;
    }

    try {
        size_t used = 0;
        student.id = stoi(idText, &used);
        if (used != idText.size() || student.id <= 0) return false;

        student.marks[0] = stod(mark1Text, &used);
        if (used != mark1Text.size()) return false;

        student.marks[1] = stod(mark2Text, &used);
        if (used != mark2Text.size()) return false;

        student.marks[2] = stod(mark3Text, &used);
        if (used != mark3Text.size()) return false;
    } catch (...) {
        return false;
    }

    if (name.find_first_not_of(" \t") == string::npos ||
        !isfinite(student.marks[0]) || !isfinite(student.marks[1]) ||
        !isfinite(student.marks[2])) {
        return false;
    }

    for (double mark : student.marks) {
        if (mark < 0.0 || mark > 100.0) return false;
    }

    student.name = name;
    return true;
}

void loadRecords(vector<Student>& students) {
    ifstream file("students.txt");
    if (!file) {
        cout << "No saved file found. Starting with an empty class.\n";
        return;
    }

    vector<Student> loadedStudents;
    string line;
    int skippedLines = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        Student student;
        if (!parseStudentLine(line, student) ||
            findStudentIndex(loadedStudents, student.id) != -1) {
            ++skippedLines;
            continue;
        }

        loadedStudents.push_back(student);
    }

    students = loadedStudents;
    cout << students.size() << " record(s) loaded.";
    if (skippedLines > 0) {
        cout << " " << skippedLines << " invalid or duplicate line(s) skipped.";
    }
    cout << '\n';
}

void displayMenu() {
    cout << "\nSTUDENT ACADEMIC MANAGEMENT SYSTEM\n";
    cout << "1. Register student\n";
    cout << "2. List students\n";
    cout << "3. Search by ID\n";
    cout << "4. Update marks\n";
    cout << "5. Class statistics\n";
    cout << "6. Top student\n";
    cout << "7. Pass list\n";
    cout << "8. Exit\n";
    cout << "\n";
}

int main() {
    vector<Student> students;
    students.reserve(10); 

    loadRecords(students);

    bool running = true;
    while (running) {
        displayMenu();

        int choice;
        if (!readInteger("Choose an option (1-8): ", choice)) {
            cout << "\nInput closed. Saving records before exit.\n";
            saveRecords(students);
            break;
        }

        switch (choice) {
            case 1:
                registerStudent(students);
                break;
            case 2:
                listStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateMarks(students);
                break;
            case 5:
                classStatistics(students);
                break;
            case 6:
                topStudent(students);
                break;
            case 7:
                passList(students);
                break;
            case 8:
                saveRecords(students);
                cout << "Thank you for using the system. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid menu choice. Please choose from 1 to 8.\n";
        }
    }

    return 0;
}
