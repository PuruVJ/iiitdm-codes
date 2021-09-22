#include <iostream>
using namespace std;

class Account {
 public:
  long long int accountNo;
  double balance, intrestRate, feeCharged;
  Account *next;

  Account(double balanceInput = 0) {
    if (balanceInput < 0) {
      cout << "Account balance can't be negative" << endl;
      balance = 0;

      return;
    }

    balance = balanceInput;
  }

  bool searchAccountNo(Account *headRef, long long int accountInput) {
    while (headRef != NULL) {
      if (headRef->accountNo == accountInput) {
        cout << "account no already registered." << endl;
        return true;
      }

      headRef = headRef->next;
    }

    return false;
  }

  Account *create_account(Account *headRef) {
    int i = 1;

    Account *newNode = new Account();

    newNode->balance = balance;
    newNode->intrestRate = 0;

    while (i) {
      cout << "enter your account no : ";
      cin >> newNode->accountNo;
      i = searchAccountNo(headRef, newNode->accountNo);
    }

    newNode->next = NULL;

    if (headRef == NULL) {
      headRef = newNode;
    } else {
      headRef->next = newNode;
      headRef = headRef->next;
    }

    return headRef;
  }

  bool credit(Account *headRef, long long int no, double amount) {
    while (headRef != NULL) {
      if (headRef->accountNo == no) {
        headRef->balance = headRef->balance + amount;
        return (1);
      }
      headRef = headRef->next;
    }
    cout << "there is no account with these details " << endl;
    return (0);
  }

  bool debit(Account *headRef, long long int no, double amount) {
    while (headRef != NULL) {
      if (headRef->accountNo == no) {
        if (headRef->balance >= amount) {
          headRef->balance = headRef->balance - amount;
          return true;
        } else {
          cout << "Account balance insufficient." << endl;
          return false;
        }
      }

      headRef = headRef->next;
    }

    cout << "there is no account with these details " << endl;
    return false;
  }

  double print(Account *headRef, long long int no) {
    while (headRef != NULL) {
      if (headRef->accountNo == no) return headRef->balance;

      headRef = headRef->next;
    }

    cout << "there is no account with these details " << endl;
    return 0;
  }
};

class SavingsAccount : public Account {
 public:
  double intrestRate;

  SavingsAccount(double balance, double intrest = 0.50) : Account(balance) {
    this->intrestRate = intrest;
  }

  double calculateInterest(Account *headRef, long long int no) {
    if (headRef == NULL) {
      cout << "There are no savings accounts registered ";
      return 0;
    }

    double rate;
    while (headRef != NULL) {
      if (headRef->accountNo == no)
        return headRef->balance * headRef->intrestRate;

      headRef = headRef->next;
    }
    cout << "No account with such details \nPlease try again" << endl;
    return 0;
  }

  double getTotalAmount(Account *headRef, long long int no) {
    if (headRef == NULL) {
      cout << "No savings accounts registered ";
      return (0);
    }

    while (headRef != NULL) {
      if (headRef->accountNo == no)
        return headRef->balance * headRef->intrestRate + headRef->balance;

      headRef = headRef->next;
    }

    cout << "there is no account with these details" << endl;
    return 0;
  }

  void updateIntrest(Account *headRef, long long int no, double rate) {
    if (headRef == NULL) {
      cout << "list is empty, no savings accounts registered ";
      return;
    }

    while (headRef != NULL) {
      if (headRef->accountNo == no) {
        cout << "intrest rate is updated from " << headRef->intrestRate;

        headRef->intrestRate = rate;

        cout << " to  " << rate << endl;
        return;
      }

      headRef = headRef->next;
    }

    cout << "there is no account with these details " << endl;
  }

  Account *create_account(Account *headRef);

} s(0, 0);

Account *SavingsAccount ::create_account(Account *headRef) {
  Account *temp = NULL;

  temp = Account::create_account(headRef);
  temp->intrestRate = intrestRate;

  return temp;
}

class CheckingAccount : public Account {
 public:
  double feeCharged;

  CheckingAccount(double balance, double charge = 0.01) : Account(balance) {
    this->feeCharged = charge;
  }

  Account *create_account(Account *headRef) {
    Account *temp = NULL;

    temp = Account::create_account(headRef);
    temp->feeCharged = feeCharged;

    return temp;
  }

  void credit(Account *headRef, long long int no, double amount) {
    if (headRef == NULL) {
      cout << "list is empty ,  no checking accounts registered ";
      return;
    }

    bool userTaxed = Account::credit(headRef, no, amount);

    if (userTaxed) {
      while (headRef != NULL) {
        if (headRef->accountNo == no) {
          headRef->balance = headRef->balance - headRef->feeCharged;

          cout << "charge  = " << headRef->feeCharged << endl;
          cout << "total amount = " << headRef->balance << endl;
        }

        headRef = headRef->next;
      }
    }
  }

  void debit(Account *headRef, long long int no, double amount) {
    if (headRef == NULL) {
      cout << "No checking accounts registered ";
      return;
    }
    double amount_original = Account::print(headRef, no);
    bool tax = Account::debit(headRef, no, amount);

    if (tax == true) {
      while (headRef != NULL) {
        if (headRef->accountNo == no) {
          if (headRef->balance >= headRef->feeCharged) {
            headRef->balance = headRef->balance - headRef->feeCharged;
            cout << "Charge amount = " << headRef->feeCharged << endl;
            cout << "Total amount = " << headRef->balance << endl;

          } else {
            headRef->balance = 0.00;
            Account ::credit(headRef, no, amount_original);
            cout << "Not sufficient money" << endl;
            cout << "Total amount in account is  = " << headRef->balance
                 << endl;
          }
        }

        headRef = headRef->next;
      }
    }
  }

  void updateFeeCharge(Account *headRef, long long int no, double fee) {
    if (headRef == NULL) {
      cout << "No checking accounts registered ";
      return;
    }

    while (headRef != NULL) {
      if (headRef->accountNo == no) {
        cout << "Fee charged is updated from " << headRef->feeCharged;

        headRef->feeCharged = fee;

        cout << "  to " << fee << endl;
      }

      headRef = headRef->next;
    }

    cout << "\nWrong details " << endl;
  }

  void printFee(Account *headRef, long long int no) {
    if (headRef == NULL) {
      cout << "\nNo checking accounts registered ";
      return;
    }
    while (headRef != NULL) {
      if (headRef->accountNo == no) {
        cout << "Fee charge : " << headRef->feeCharged << endl;
        return;
      }
      headRef = headRef->next;
    }
    cout << "There is no account with these details " << endl;
  }

} s1(0, 0);

int main() {
  long long int no;

  int choice, choice_opt, count = 0, count1 = 0;

  double fee, rate, amount;

  Account *head, *head1, *temp, *temp1;

  while (true) {
    cout << "\n";
    cout << "\n\n     WELCOME TO OUR BANK    \n\n";
    cout << "\n\n";
    cout << "\n1. Open account(savings/checking) \n2. Credit(savings/checking) "
            " \n3. Debit(savings/checkings)  \n4. Change/update intrset rate  "
            "\n5. Calculate intrest \n6. Calculate and update intrest\n7. "
            "Change/update fee amount \n8. Print checking fee \n9. Transaction "
            "and Update ";
    cout << "\n10. Exit" << endl;
    cout << "\n Enter your choice : ";

    cin >> choice;

    if (choice == 1) {
      cout << "1) Savings account \n2) Checking account" << endl;
      cout << "\n Enter your choice : ";
      cin >> choice_opt;
      if (choice_opt == 1) {
        cout << "Enter balance: ";
        cin >> amount;
        cout << "Savings intrest: ";
        cin >> rate;
        SavingsAccount a1(amount, rate);
        head = a1.create_account(head);
        count++;
        if (count == 1) {
          temp = head;
        }
      } else if (choice_opt == 2) {
        cout << "Enter balance amount: ";
        cin >> amount;
        cout << " Fee charge " << endl;
        cin >> fee;
        CheckingAccount a1(amount, fee);
        head1 = a1.create_account(head1);
        count1++;
        if (count1 == 1) {
          temp1 = head1;
        }
      } else {
        cout << "Please try again\n" << endl;
      }

    } else if (choice == 2) {
      cout << "1) Savings account \n2) Checking account" << endl;
      cout << "\n Enter your choice : ";
      cin >> choice_opt;
      if (choice_opt == 1) {
        cout << "\nPlease Enter account no ";
        cin >> no;
        cout << "\nPlease enter Credit amount :";
        cin >> amount;
        s.credit(temp, no, amount);
      } else if (choice_opt == 2) {
        cout << "\nPlease Enter account no ";
        cin >> no;
        cout << "\nPlease enter Credit amount :";
        cin >> amount;
        s1.credit(temp1, no, amount);
      } else {
        cout << "Please try again" << endl;
      }

    } else if (choice == 3) {
      cout << "1) Savings account \n2) Checking account" << endl;
      cout << "\n Enter your choice : ";
      cin >> choice_opt;
      if (choice_opt == 1) {
        cout << "Enter account number";
        cin >> no;
        cout << " Amount to be debit : ";
        cin >> amount;
        s.debit(temp, no, amount);
      } else if (choice_opt == 2) {
        cout << "Enter account number: ";
        cin >> no;
        cout << "Amount to be debit : ";
        cin >> amount;
        s1.debit(temp1, no, amount);
      } else {
        cout << "Enter a valid choice" << endl;
      }

    } else if (choice == 4) {
      cout << "Enter account nuumber:";
      cin >> no;
      cout << " New intrest rate : ";
      cin >> rate;
      s.updateIntrest(temp, no, rate);

    } else if (choice == 5) {
      cout << "Enter account no : ";
      cin >> no;
      cout << "Intrest amount = " << s.calculateInterest(temp, no);

    } else if (choice == 6) {
      cout << "Enter account number: ";
      cin >> no;
      cout << " New intrest rate : ";
      cin >> rate;
      if (temp != NULL) {
        cout << "intrest amount = " << s.calculateInterest(temp, no) << endl;
        cout << "total amount = " << s.getTotalAmount(temp, no) << endl;
        s.updateIntrest(temp, no, rate);
      } else {
        cout << "No accounts registered";
      }

    } else if (choice == 7) {
      cout << "Enter account number: ";
      cin >> no;
      cout << "New fee charge : ";
      cin >> fee;
      s1.updateFeeCharge(temp1, no, fee);

    } else if (choice == 8) {
      cout << "Enter account nunber : ";
      cin >> no;
      s1.printFee(temp1, no);

    } else if (choice == 9) {
      cout << "\nPlease Enter account no ";
      cin >> no;
      cout << "\nPlease enter Credit amount :";
      cin >> amount;
      s1.debit(temp1, no, amount);

    } else if (choice == 10)
      exit(0);
    else
      cout << "Enter a valid choice";
  }

  return 0;
}
