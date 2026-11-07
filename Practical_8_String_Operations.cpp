#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string fullName;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    if (fullName.empty()) {
        cout << "No name was entered.\n";
        return 0;
    }

    cout << "\nName: " << fullName << '\n';
    cout << "Length: " << fullName.length() << " characters\n";
    cout << "First character: " << fullName[0] << '\n';

    bool hasSpace = false;

    for (char character : fullName) {
        if (character == ' ') {
            hasSpace = true;
            break;
        }
    }

    if (hasSpace) {
        cout << "Contains a space: Yes\n";
    } else {
        cout << "Contains a space: No\n";
    }

    
    int numericID;
    cout << "\nEnter a numeric ID: ";
    cin >> numericID;

    if (fullName.length() >= 3) {
        string username = fullName.substr(0, 3) + to_string(numericID);
        cout << "Generated username: " << username << '\n';
    } else {
        cout << "The name has fewer than three characters.\n";
        cout << "A username cannot be generated from its first three characters.\n";
    }

    
    string firstWord, secondWord;

    cout << "\nEnter the first word: ";
    cin >> firstWord;

    cout << "Enter the second word: ";
    cin >> secondWord;

    if (firstWord == secondWord) {
        cout << "The two words are equal.\n";
    } else {
        cout << "The two words are not equal.\n";
    }

    string lowerFirst = firstWord;
    string lowerSecond = secondWord;

    for (char &character : lowerFirst) {
        character = static_cast<char>(
            tolower(static_cast<unsigned char>(character))
        );
    }

    for (char &character : lowerSecond) {
        character = static_cast<char>(
            tolower(static_cast<unsigned char>(character))
        );
    }

    if (lowerFirst == lowerSecond) {
        cout << "Ignoring uppercase and lowercase letters, the words match.\n";
    } else {
        cout << "The words still do not match.\n";
    }

    return 0;
}
