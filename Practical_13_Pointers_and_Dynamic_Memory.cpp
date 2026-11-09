#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score = 75;
    int* pointer = &score;

    cout << "Score: " << score << '\n';
    cout << "Address of score: " << &score << '\n';
    cout << "Address stored in pointer: " << pointer << '\n';
    cout << "Value through pointer: " << *pointer << '\n';

    *pointer = 90;
    cout << "\nAfter changing *pointer:\n";
    cout << "score = " << score << '\n';
    cout << "*pointer = " << *pointer << '\n';

    int n;
    cout << "\nEnter dynamic array size (1-1000): ";
    cin >> n;

    if (!cin || n < 1 || n > 1000) {
        cout << "Invalid array size.\n";
        return 0;
    }

    int* values = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];

        if (!cin) {
            cout << "Invalid input. Releasing allocated memory.\n";
            delete[] values;
            values = nullptr;
            return 0;
        }
    }

    cout << "Dynamic array values: ";
    for (int i = 0; i < n; i++) cout << values[i] << " ";
    cout << '\n';

    delete[] values;
    values = nullptr;
    cout << "Array memory released. Pointer is "
         << (values == nullptr ? "nullptr" : "not null") << ".\n";

    cout << "\nVECTOR VERSION\n";
    vector<int> saferValues;
    int count;
    cout << "How many values (1-1000)? ";
    cin >> count;

    if (!cin || count < 1 || count > 1000) {
        cout << "Invalid vector size.\n";
        return 0;
    }

    for (int i = 0; i < count; i++) {
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        if (!cin) {
            cout << "Invalid input.\n";
            return 0;
        }
        saferValues.push_back(value);
    }

    cout << "Vector values: ";
    for (int value : saferValues) cout << value << " ";
    cout << "\nVector memory is managed automatically.\n";

    return 0;
}
