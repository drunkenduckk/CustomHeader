#include <iostream>
#include <string>
#include <limits>
#include "mathutils.h"
#include "stringutils.h"

using namespace std;

void showMainMenu();
void handleMathOperations();
void handleStringOperations();
void clearInputBuffer();
int getIntegerInput(const string& prompt);
string getStringInput(const string& prompt);

int main() {
    cout << "===========================================" << endl;
    cout << "  Custom Header Files Made By DrunkenDuck" << endl;
    cout << "===========================================" << endl;
    cout << "This program demonstrates using custom header files" << endl;
    cout << "for math and string utilities." << endl << endl;
    
    int choice;
    
    do {
        showMainMenu();
        choice = getIntegerInput("Now Choose: ");
        
        switch (choice) {
            case 1:
                handleMathOperations();
                break;
            case 2:
                handleStringOperations();
                break;
            case 3:
                cout << "\nThank you for using my Custom Header " << endl;
                cout << "Peace Out :)";
                break;
            default:
                cout << "\nLmao! Select 1, 2, or 3." << endl;
        }
        
        if (choice != 3) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cout << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}

void showMainMenu() {
    cout << "==================================" << endl;
    cout << "            MAIN MENU" << endl;
    cout << "==================================" << endl;
    cout << "1. Math Operations" << endl;
    cout << "2. String Operations" << endl;
    cout << "3. Exit" << endl;
    cout << "==================================" << endl;
}

void handleMathOperations() {
    cout << "\n=== MATH OPERATIONS ===" << endl;
    cout << "Things You Can Select From:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Wanna Go Back To Main Menu?" << endl;
    
    int operation = getIntegerInput("Select One: ");
    
    if (operation == 5) return;
    
    if (operation < 1 || operation > 4) {
        cout << "WTF MAN ? Select Only From 1-5...." << endl;
        return;
    }
    
    int num1 = getIntegerInput("First Number: ");
    int num2 = getIntegerInput("Second Number: ");
    
    try {
        int result;
        string operationName;
        
        switch (operation) {
            case 1:
                result = MathUtils::add(num1, num2);
                operationName = "Addition";
                cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:
                result = MathUtils::subtract(num1, num2);
                operationName = "Subtraction";
                cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:
                result = MathUtils::multiply(num1, num2);
                operationName = "Multiplication";
                cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:
                result = MathUtils::divide(num1, num2);
                operationName = "Division";
                cout << "\nResult: " << num1 << " / " << num2 << " = " << result << endl;
                break;
        }
        
        cout << operationName << " DONE !" << endl;
        
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void handleStringOperations() {
    cout << "\n=== STRING OPERATIONS ===" << endl;
    cout << "Available operations:" << endl;
    cout << "1. Convert to Uppercase" << endl;
    cout << "2. Convert to Lowercase" << endl;
    cout << "3. Check if Palindrome" << endl;
    cout << "4. Back to main menu" << endl;
    
    int operation = getIntegerInput("Choose operation: ");
    
    if (operation == 4) return;
    
    if (operation < 1 || operation > 3) {
        cout << "Invalid operation selected!" << endl;
        return;
    }
    
    string input = getStringInput("Press 'Enter' Then Type Your String");
    
    switch (operation) {
        case 1: {
            string result = StringUtils::toUpper(input);
            cout << "\nOriginal: \"" << input << "\"" << endl;
            cout << "Uppercase: \"" << result << "\"" << endl;
            break;
        }
        case 2: {
            string result = StringUtils::toLower(input);
            cout << "\nOriginal: \"" << input << "\"" << endl;
            cout << "Lowercase: \"" << result << "\"" << endl;
            break;
        }
        case 3: {
            bool result = StringUtils::isPalindrome(input);
            cout << "\nString: \"" << input << "\"" << endl;
            cout << "Is palindrome: " << (result ? "YES" : "NO") << endl;
            break;
        }
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            clearInputBuffer();
            return value;
        } else {
            cout << "WTF MAN ? Enter a integer........." << endl;
            clearInputBuffer();
        }
    }
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    clearInputBuffer();
    getline(cin, input);
    return input;
}
