#include <iostream>
using namespace std;

int main() {
    double balance = 25000.0;
    double amount;
    int choice;

    const int correctPIN = 1234;
    int enteredPIN;
    bool authenticated = false;

    for (int attempt = 1; attempt <= 3; attempt++) {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == correctPIN) {
            authenticated = true;
            break; 
        }

        cout << "Incorrect PIN.\n";
    }

    if (!authenticated) {
        cout << "Too many incorrect attempts. Access denied.\n";
        return 0;
    }

    do {
        cout << "\n===== ATM MENU =====\n";
        cout << "1. Check balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current balance: " << balance << " FCFA\n";
                break;

            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Deposit must be greater than zero.\n";
                } else {
                    balance += amount;
                    cout << "Deposit successful.\n";
                }
                break;

            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Withdrawal must be greater than zero.\n";
                } else if (amount > balance) {
                    cout << "Insufficient balance.\n";
                } else {
                    balance -= amount;
                    cout << "Withdrawal successful.\n";
                }
                break;

            case 4:
                cout << "Thank you for using the ATM.\n";
                break;

            default:
                cout << "Invalid menu option.\n";
        }

    } while (choice != 4);

    cout << "Final balance: " << balance << " FCFA\n";
    return 0;
}
