#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159;
double area(double side) {
    return side * side;
}
double area(double length, double width) {
    return length * width;
}
double circleArea(double radius) {
    return PI * radius * radius;
}
void printResult(int result) {
    cout << "Integer result: " << result << endl;
}
void printResult(double result) {
    cout << "Area: " << result << endl;
}

int main() {
    int choice;
    double side, length, width, radius;
    cout << fixed << setprecision(2);
    cout << "===== AREA CALCULATOR =====" << endl;
    cout << "1. Square" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Circle" << endl;
    cout << "Choose a shape: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter square side: ";
            cin >> side;
            printResult(area(side));
            break;

        case 2:
            cout << "Enter rectangle length: ";
            cin >> length;
            cout << "Enter rectangle width: ";
            cin >> width;
            printResult(area(length, width));
            break;

        case 3:
            cout << "Enter circle radius: ";
            cin >> radius;
            printResult(circleArea(radius));
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
