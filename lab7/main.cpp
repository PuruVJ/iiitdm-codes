/**
After defining the classes in this hierarchy, write a menu-driven program with
the following options,

1. Open Account (Savings or Checking Account)
2. Credit (Savings or Checking Account)
3. Debit (Savings or Checking Account)
4. Change/Update Interest rate (Savings Account)
5. Calculate Interest (Savings Account - Print)
6. Calculate and Update Interest (Savings Account - Credit)
7. Change/Update Fee Amount (Checking Account)
8. Print Checking Fee (Checking Account)
9. Transact and Update (Checking Account - Debit)
10. Exit
 */

#include <iostream>
using namespace std;

class Account {
 protected:
  double account_balance = 0;
  int account_number;

 public:
  Account(double accBalance) {
    if (accBalance < 0) {
      // Error out
      cout << "Account balance should be 0.0 or more\n";
      return;
    }
    this->account_balance = accBalance;
  }

  void createAccount(int accountNumber) {
    this->account_number = accountNumber;
  }

  bool credit(double amount) {
    if (amount < 0) {
      cout << "Amount can't be negative\n";
      return false;
    }

    this->account_balance += amount;
    return true;
  }

  bool debit(double amount) {
    if (amount < 0) {
      cout << "Amount can't be negative\n";
      return false;
    }

    if (amount > this->account_balance) {
      cout << "Debit amount exceeded account balance\n";
      return false;
    }

    this->account_balance -= amount;
    return true;
  }
};

class SavingsAccount : public Account {
 private:
  double interest_rate;

 public:
  SavingsAccount(double accBalance, double interest) : Account(accBalance) {
    this->interest_rate = interest;
  }

  double calculateInterest() {
    return this->account_balance * this->interest_rate;
  }
};

class CheckingAccount : public Account {
 private:
  double fee_per_transaction;

 public:
  CheckingAccount(double accBalance, double fee) : Account(accBalance) {
    if (fee < 0) {
      cout << "Fee can't be negative.\n";
      return;
    }

    this->fee_per_transaction = fee;
  }

  void credit(double amount) {
    bool credited = Account::credit(amount);

    if (credited) {
      // Deduct the fee
      Account::debit(fee_per_transaction);
    }
  }

  void debit(double amount) {
    bool debited = Account::debit(amount);

    if (debited) {
      // Deduct the fee
      Account::debit(fee_per_transaction);
    }
  }
};

// // Linked list stuff
// class SavingsNode {
//  public:
//   SavingsAccount account;
//   SavingsNode* next;

//   SavingsNode() {}

//   SavingsNode(SavingsAccount acc) {
//     this->account = acc;
//     this->next = NULL;
//   }
// };

// class CheckingNode {
//  public:
//   CheckingAccount account;
//   CheckingNode* next;
// };

int main() {
  cout << "1. Open Account (Savings or Checking Account)\n";
  cout << "2. Credit (Savings or Checking Account)\n";
  cout << "3. Debit (Savings or Checking Account)\n";
  cout << "4. Change/Update Interest rate (Savings Account)\n";
  cout << "5. Calculate Interest (Savings Account - Print)\n";
  cout << "6. Calculate and Update Interest (Savings Account - Credit)\n";
  cout << "7. Change/Update Fee Amount (Checking Account)\n";
  cout << "8. Print Checking Fee (Checking Account)\n";
  cout << "9. Transact and Update (Checking Account - Debit)\n";
  cout << "10. Exit\n";

  int choice;

  while (true) {
  }

  return 0;
}