#include <iostream>
using namespace std;

void addBonusByValue(int mark, int bonus) {
    mark += bonus;
    if (mark > 100) mark = 100;
    cout << "Inside value function: " << mark << '\n';
}

void addBonusByReference(int& mark, int bonus) {
    mark += bonus;
    if (mark > 100) mark = 100;
    cout << "Inside reference function: " << mark << '\n';
}

void swapValues(int& a, int& b) {
    int temporary = a;
    a = b;
    b = temporary;
}

int main() {
    int bonus;
    cout << "Enter bonus: ";
    cin >> bonus;

    if (!cin || bonus < 0) {
        cout << "Bonus must be a non-negative whole number.\n";
        return 0;
    }

    int valueMark = 60;
    cout << "\nVALUE PARAMETER\nBefore: " << valueMark << '\n';
    addBonusByValue(valueMark, bonus);
    cout << "After: " << valueMark << '\n';

    int referenceMark = 60;
    cout << "\nREFERENCE PARAMETER\nBefore: " << referenceMark << '\n';
    addBonusByReference(referenceMark, bonus);
    cout << "After: " << referenceMark << '\n';

    int first = 10, second = 20;
    cout << "\nBefore swap: " << first << ", " << second << '\n';
    swapValues(first, second);
    cout << "After swap: " << first << ", " << second << '\n';

    return 0;
}
