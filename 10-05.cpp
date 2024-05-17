#include <iostream>
#include <string>
using namespace std;

class ArgumentException {
private:
    string message;

public:
    ArgumentException(const string& msg) : message(msg) {}

    const string& GetMessage() const {
        return message;
    }
};

class InsufficientFundsException {
private:
    string message;

public:
    InsufficientFundsException(const string& msg) : message(msg) {}

    const string& GetMessage() const {
        return message;
    }
};

class BankAccount {
private:
    string fullName;
    string accountNumber;
    double currentBalance;
    double credit;
    static const double creditLimit;
    bool canUseCredit;

public:
    BankAccount(const string& name, const string& accNum, double initialBalance, bool useCredit = true)
        : fullName(name), accountNumber(accNum), currentBalance(initialBalance), credit(0), canUseCredit(useCredit) {}

    void Deposit(double amount) {
        if (amount <= 0) {
            throw ArgumentException("Amount to deposit must be positive");
        }
        currentBalance += amount;
        cout << "Deposited: $" << amount << endl;
        DisplayAccountInfo();
    }

    void Withdraw(double amount) {
        if (amount <= 0) {
            throw ArgumentException("Amount to withdraw must be positive");
        }

        if (amount > currentBalance + (canUseCredit ? creditLimit - credit : 0)) {
            throw InsufficientFundsException("Insufficient funds");
        }

        if (amount > currentBalance) {
            double remainingBalance = currentBalance;
            double remainingCredit = amount - currentBalance;
            currentBalance = 0;
            if (canUseCredit && remainingCredit <= creditLimit - credit) {
                credit += remainingCredit;
                cout << "Withdrawn: $" << remainingBalance << " (from balance) and $" << remainingCredit << " (using credit)" << endl;
            }
            else {
                cerr << "Error: Insufficient funds" << endl;
                return;
            }
        }
        else {
            currentBalance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
        DisplayAccountInfo();
    }

    double GetCurrentBalance() const {
        return currentBalance;
    }

    double GetCredit() const {
        return credit;
    }

    double GetCreditLimit() const {
        return creditLimit;
    }

    void SetCanUseCredit(bool canUse) {
        canUseCredit = canUse;
    }

    bool CanUseCredit() const {
        return canUseCredit;
    }

    void DisplayAccountInfo() const {
        cout << "Account Information:" << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << currentBalance << endl;
        cout << "Credit Used: $" << credit << endl;
        cout << "Credit Limit: $" << creditLimit << endl;
        cout << "Can Use Credit: " << (canUseCredit ? "Yes" : "No") << endl;
    }
};

const double BankAccount::creditLimit = 1000.0;

class ATM {
public:
    static void WithdrawMoney(BankAccount& account, double amount) {
        if (amount < 0) {
            cout << "Error: Invalid amount" << endl;
            return;
        }

        try {
            account.Withdraw(amount);
        }
        catch (const InsufficientFundsException& ex) {
            cout << "Error: " << ex.GetMessage() << endl;
        }
        catch (const ArgumentException& ex) {
            cout << "Error: " << ex.GetMessage() << endl;
        }
    }
};

int main() {
    BankAccount account("PeRSiK", "4931 3484 3940 5810", 500.0);

    account.DisplayAccountInfo();

    int choice = -1;
    while (choice != 0) {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Deposit money" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Toggle credit usage" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (0-3): ";

        cin >> choice;

        if (choice == 1) {
            double amount;
            cout << "Enter amount to deposit: $";
            cin >> amount;
            try {
                account.Deposit(amount);
            }
            catch (const ArgumentException& ex) {
                cout << "Error: " << ex.GetMessage() << endl;
            }
        }
        else if (choice == 2) {
            double amount;
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            ATM::WithdrawMoney(account, amount);
        }
        else if (choice == 3) {
            account.SetCanUseCredit(!account.CanUseCredit());
            cout << "Credit usage toggled: " << (account.CanUseCredit() ? "On" : "Off") << endl;
        }
        else if (choice == 0) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
