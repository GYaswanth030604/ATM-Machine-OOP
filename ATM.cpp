#include <iostream>
using namespace std;

class ATM {
private:
    double balance;

public:
    // Constructor
    ATM(double initialBalance) {
        balance = initialBalance;
    }

    // Check Balance
    void getBalance() {
        cout << "\nCurrent Balance: " << balance << endl;
    }

    // Deposit Money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit Successful!" << endl;
        cout << "Updated Balance: " << balance << endl;
    }

    // Withdraw Money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
            cout << "Remaining Balance: " << balance << endl;
        }
    }
};

int main() {
    int choice;
    double amount;
    string transaction;

    ATM atm(10000); // Initial balance = 10,000

    do {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Cash" << endl;
        cout << "3. Deposit Cash" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                atm.getBalance();
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                atm.withdraw(amount);
                break;

            case 3:
                cout << "Enter deposit amount: ";
                cin >> amount;
                atm.deposit(amount);
                break;

            case 4:
                cout << "Thank you! Have a nice day." << endl;
                break;

            default:
                cout << "Invalid Choice. Please try again." << endl;
        }

        if(choice != 4) {
            cout << "\nDo you want another transaction? (YES/NO): ";
            cin >> transaction;
        }

    } while(transaction == "YES" || transaction == "yes");

    return 0;
}
