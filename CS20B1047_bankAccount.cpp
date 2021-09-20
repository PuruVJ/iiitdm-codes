#include <iomanip>
#include <iostream>
#include <list>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
#define FT_YEL "\x1B[0;33m"
#define FT_B_RED "\x1B[1;31m"
#define FT_B_GRN "\x1B[1;32m"
#define FT_B_YEL "\x1B[1;33m"
#define FT_B_WHT "\x1B[1;37m"
#define FT_NRM "\x1B[0m"
#define clearscreen() \
  { cout << "\033[2J\033[1;1H"; }

typedef struct interest_hist_node {
  int no_of_months;
  double interest_rate;
  double amount;
} interest_hist_node;

class account {
 private:
  double balance;
  int account_number;

 public:
  account(double initial_balance, int account_number) {
    if (initial_balance >= 0)
      this->balance = initial_balance;
    else {
      cerr << "Initial balance should not be negative, and initial balance set "
              "to 0.0\n";
      this->balance = 0.0;
    }
    this->account_number = account_number;
  }
  double get_balance() { return balance; }
  bool is_exist(int account_number) {
    if (this->account_number == account_number) {
      return true;
    }
    return false;
  }
  bool debit(float debit_amount) {
    if (debit_amount < 0 || debit_amount > this->balance) {
      return false;
    } else {
      this->balance -= debit_amount;
      return true;
    }
  }
  bool credit(float credit_amount) {
    if (credit_amount < 0) {
      return false;
    } else {
      this->balance += credit_amount;
      return true;
    }
  }
};

class savingsAccount : public account {
 private:
  double interest_rate;
  int no_of_months;
  list<interest_hist_node> i1;

 public:
  savingsAccount(int account_number, double initial_amount,
                 double interest_rate)
      : account{initial_amount, account_number} {
    this->no_of_months = 0;
    if (interest_rate >= 0)
      this->interest_rate = interest_rate;
    else {
      cerr << "Interest rate must be non-negative, and interest rate set to "
              "5%\n";
      this->interest_rate = 5.0;
    }
  }
  bool update_interest_rate(double interest_rate) {
    if (interest_rate >= 0) {
      if (this->no_of_months != 0) {
        interest_hist_node node;
        node.interest_rate = this->interest_rate;
        node.no_of_months = this->no_of_months;
        node.amount = get_balance();
        i1.push_back(node);
        this->no_of_months = 0;
      }
      this->interest_rate = interest_rate;
      return true;
    } else {
      cerr << "Interest rate should be non-negative\n";
      return false;
    }
  }
  double calculateInterest(int no_of_months) {
    this->no_of_months += no_of_months;
    list<interest_hist_node>::iterator it;
    double total_interest = 0;
    cout << "No. of months\tInterest Rate \t    Amount     \tInterest Amount\n";
    for (it = i1.begin(); it != i1.end(); ++it) {
      double interest_amount =
          (it->amount * it->no_of_months * it->interest_rate) / (double)1200;
      total_interest += interest_amount;
      printf("    %3d      \t    %3.2lf%c    \t  %10.2lf  \t    %10.2lf\n",
             it->no_of_months, it->interest_rate, '%', get_balance(),
             interest_amount);
    }
    double interest_amount =
        (get_balance() * this->no_of_months * this->interest_rate) /
        (double)1200;
    total_interest += interest_amount;
    printf("    %3d      \t    %3.2lf%c    \t  %10.2lf  \t    %10.2lf\n",
           this->no_of_months, this->interest_rate, '%', get_balance(),
           interest_amount);
    printf("\t\t\t     Total interest amount: %10.2lf\n", total_interest);
    return total_interest;
  }
  void update_interest() {
    double total_interest = this->calculateInterest(0);
    account::credit(total_interest);
    cout << "Rs." << total_interest << " credited to your account.\n";
    this->i1.clear();
    this->no_of_months = 0;
  }
};

class checkingAccount : public account {
 private:
  double transaction_fee;

 public:
  checkingAccount(int account_number, double initial_amount,
                  double transaction_fee)
      : account{initial_amount, account_number} {
    if (transaction_fee >= 0)
      this->transaction_fee = transaction_fee;
    else {
      cerr << "Transaction fee must be non-negative\n";
      this->transaction_fee = 5.0;
    }
  }
  bool debit(double debit_amount) {
    if (debit_amount >= 0) {
      double total_debit = debit_amount + this->transaction_fee;
      return account::debit(total_debit);
    } else {
      return false;
    }
  }
  bool credit(double credit_amount) {
    if (credit_amount >= 0) {
      double total_credit = credit_amount + this->transaction_fee;
      return account::credit(total_credit);
    } else {
      return false;
    }
  }
  bool update_transaction_fee(double transaction_fee) {
    if (transaction_fee >= 0) {
      this->transaction_fee = transaction_fee;
      return true;
    } else {
      cerr << "Transaction fee should be non-negative\n";
      return false;
    }
  }
  double get_transaction_fee() { return this->transaction_fee; }
  void print_transaction_fee() {
    cout << FT_B_YEL << "Transaction fee: " << this->transaction_fee << "\n"
         << FT_NRM;
  }
};

int check(list<savingsAccount> l1, int account_number) {
  list<savingsAccount>::iterator it;
  int i = 0;
  for (it = l1.begin(); it != l1.end(); ++it, ++i) {
    if (it->is_exist(account_number)) {
      return i;
    }
  }
  return -1;
}
int check(list<checkingAccount> l1, int account_number) {
  list<checkingAccount>::iterator it;
  int i = 0;
  for (it = l1.begin(); it != l1.end(); ++it, ++i) {
    if (it->is_exist(account_number)) {
      return i;
    }
  }
  return -1;
}
int main() {
  list<savingsAccount> savings_acc_list;
  list<checkingAccount> checking_acc_list;
  int choice;
  int account_number;
  double initial_amount, transaction_fee, interest_rate, debit_amount,
      credit_amount;
  while (1) {
    int choice2 = 3;
    cout << "\n\tMENU\n";
    cout << "1.Open Account(Savings or Checking Account)\n";
    cout << "2.Credit(Savings or Checking Account)\n";
    cout << "3.Debit(Savings or Checking Account)\n";
    cout << "4.Update Interest Rate(Only Applicable for Savings account\n";
    cout << "5.Calculate Interest(Only Applicable for Saving account)\n";
    cout << "6.Calculate and Update Interest(Only applicable for Savings "
            "Account)\n";
    cout << "7.Update Fee Amount(Only Applicable for Checking Acccount)\n";
    cout << "8.Print Checking Fee(Only Applicable for Checking Account)\n";
    cout << "9.Transact and Update\n";
    cout << "10.Exit\n";
    cout << "Your choice: ";
    cin >> choice;
    clearscreen();
    switch (choice) {
      case 1: {
        while (1) {
          cout << "OPEN ACCOUNT\n";
          cout << "1.Savings Account\n";
          cout << "2.Checking Account\n";
          cout << "Your choice: ";
          cin >> choice2;

          switch (choice2) {
            case 1: {
              bool tmp = false;
              do {
                if (tmp) {
                  cout
                      << FT_B_RED
                      << "Sorry, Account number invalid or  already exists.. \n"
                      << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                cin >> account_number;

              } while (check(savings_acc_list, account_number) != -1 ||
                       account_number < 0);
              cout << "Enter the initial amount: ";
              cin >> initial_amount;
              cout << "Enter the interest rate: ";
              cin >> interest_rate;

              savingsAccount s1{account_number, initial_amount, interest_rate};

              savings_acc_list.push_back(s1);
              cout << FT_B_GRN << "Account created Successfully!! \n" << FT_NRM;
              break;
            }
            case 2: {
              bool tmp = false;
              do {
                if (tmp) {
                  cout << FT_B_RED
                       << "Sorry, Account number invalid or already exists.. \n"
                       << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                cin >> account_number;

              } while (check(checking_acc_list, account_number) != -1 ||
                       account_number < 0);
              cout << "Enter the initial amount: ";
              cin >> initial_amount;
              cout << "Enter the transaction fee: ";
              cin >> transaction_fee;
              checkingAccount c1{account_number, initial_amount,
                                 transaction_fee};
              checking_acc_list.push_back(c1);
              cout << FT_B_GRN << "Account created Successfully!! \n" << FT_NRM;

              break;
            }
            default: {
              cout << FT_B_YEL "Invalid choice.... Try again....\n" FT_NRM;
            }
          }

          if (choice2 == 1 || choice2 == 2) {
            break;
          }
        }
        break;
      }
      case 2: {
        while (1) {
          cout << "CREDIT\n";
          cout << "1.Savings Account\n";
          cout << "2.Checking Account\n";
          cout << "Your choice: ";
          cin >> choice2;
          switch (choice2) {
            case 1: {
              bool tmp = false;
              int pos;
              do {
                if (tmp) {
                  cout << FT_B_RED
                       << "Sorry, Account number does not exists..(Enter 'q' "
                          "to quit to main menu) \n"
                       << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                string str;
                cin >> str;
                if (str[0] == 'q') {
                  tmp = false;
                  break;
                }
                account_number = std::atoi(str.c_str());

              } while ((pos = check(savings_acc_list, account_number)) == -1);

              if (tmp == false) {
                break;
              }

              cout << "Enter the credit amount: ";
              cin >> credit_amount;
              list<savingsAccount>::iterator it;
              it = savings_acc_list.begin();
              for (int i = 0; i < pos; i++) {
                ++it;
              }
              if (it->credit(credit_amount)) {
                cout << FT_B_GRN << "Rs." << credit_amount
                     << " credited successfully!! \n"
                     << FT_NRM;
              } else {
                cout << FT_B_RED << "Rs." << credit_amount
                     << " credit failed, Please give valid amount \n"
                     << FT_NRM;
              }
              break;
            }
            case 2: {
              bool tmp = false;
              int pos;
              do {
                if (tmp) {
                  cout << FT_B_RED
                       << "Sorry, Account number does not exists..(Enter 'q' "
                          "to quit to main menu) \n"
                       << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                string str;
                cin >> str;
                if (str[0] == 'q') {
                  tmp = false;
                  break;
                }
                account_number = std::atoi(str.c_str());

              } while ((pos = check(checking_acc_list, account_number)) == -1);

              if (tmp == false) {
                break;
              }

              cout << "Enter the credit amount: ";
              cin >> credit_amount;
              list<checkingAccount>::iterator it;
              it = checking_acc_list.begin();
              for (int i = 0; i < pos; i++) {
                ++it;
              }
              if (it->credit(credit_amount)) {
                cout << FT_B_GRN << "Rs." << credit_amount
                     << " credited successfully!!!, And transaction fee Rs."
                     << it->get_transaction_fee() << " also debited \n "
                     << FT_NRM;
              } else {
                cout << FT_B_RED << "Rs." << credit_amount
                     << " credit failed, Please give valid amount \n"
                     << FT_NRM;
              }
              break;
            }
            default: {
              cout << FT_B_YEL "Invalid choice.... Try again....\n" FT_NRM;
            }
          }

          if (choice2 == 1 || choice2 == 2) {
            break;
          }
        }
        break;
      }
      case 3: {
        while (1) {
          cout << "DEBIT\n";
          cout << "1.Savings Account\n";
          cout << "2.Checking Account\n";
          cout << "Your choice: ";
          cin >> choice2;
          switch (choice2) {
            case 1: {
              bool tmp = false;
              int pos;
              do {
                if (tmp) {
                  cout << FT_B_RED
                       << "Sorry, Account number does not exists..(Enter 'q' "
                          "to quit to main menu) \n"
                       << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                string str;
                cin >> str;
                if (str[0] == 'q') {
                  tmp = false;
                  break;
                }
                account_number = std::atoi(str.c_str());

              } while ((pos = check(savings_acc_list, account_number)) == -1);

              if (tmp == false) {
                break;
              }

              cout << "Enter the debit amount: ";
              cin >> debit_amount;
              list<savingsAccount>::iterator it;
              it = savings_acc_list.begin();
              for (int i = 0; i < pos; i++) {
                ++it;
              }
              if (it->debit(debit_amount)) {
                cout << FT_B_GRN << "Rs." << debit_amount
                     << " debited successfully!! \n"
                     << FT_NRM;
              } else {
                cout << FT_B_RED << "Rs." << debit_amount
                     << " debit failed, Please give valid amount \n"
                     << FT_NRM;
              }
              break;
            }
            case 2: {
              bool tmp = false;
              int pos;
              do {
                if (tmp) {
                  cout << FT_B_RED
                       << "Sorry, Account number does not exists..(Enter 'q' "
                          "to quit to main menu) \n"
                       << FT_NRM;
                }
                tmp = true;
                cout << "Enter the account number: ";
                string str;
                cin >> str;
                if (str[0] == 'q') {
                  tmp = false;
                  break;
                }
                account_number = std::atoi(str.c_str());

              } while ((pos = check(checking_acc_list, account_number)) == -1);

              if (tmp == false) {
                break;
              }

              cout << "Enter the debit amount: ";
              cin >> debit_amount;
              list<checkingAccount>::iterator it;
              it = checking_acc_list.begin();
              for (int i = 0; i < pos; i++) {
                ++it;
              }
              if (it->debit(debit_amount)) {
                cout << FT_B_GRN << "Rs." << debit_amount
                     << " debited successfully !!!, And transaction fee Rs."
                     << it->get_transaction_fee() << " also debited \n"
                     << FT_NRM;
              } else {
                cout << FT_B_RED << "Rs." << debit_amount
                     << " debit failed, Please give valid amount \n"
                     << FT_NRM;
              }
              break;
            }
            default: {
              cout << FT_B_YEL "Invalid choice.... Try again....\n" FT_NRM;
            }
          }

          if (choice2 == 1 || choice2 == 2) {
            break;
          }
        }
        break;
      }

      case 4: {
        cout << "UPDATE INTEREST RATE\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(savings_acc_list, account_number)) == -1);

        if (tmp == false) {
          break;
        }
        cout << "Enter the new interest rate: ";
        cin >> interest_rate;
        list<savingsAccount>::iterator it;
        it = savings_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        if (it->update_interest_rate(interest_rate)) {
          cout << FT_B_GRN
               << "Interest rate updated successfully!!! , New interest rate: "
               << interest_rate << "%\n"
               << FT_NRM;
        } else {
          cout << FT_B_RED
               << "Interest rate update failed ,Please enter valid interest "
                  "rate\n"
               << FT_NRM;
        }

        break;
      }
      case 5: {
        cout << "CALCULATE INTEREST\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(savings_acc_list, account_number)) == -1);
        if (tmp == false) {
          break;
        }
        int no_of_months;
        while (1) {
          cout << "1.Fast forward 1 month\n";
          cout << "2.Fast forward 3 month\n";
          cout << "3.Fast forward 6 month\n";
          cout << "4.Fast forward 1 year\n";
          cout << "5.Fast forward 5 year\n";
          cout << "Your choice: ";
          cin >> choice2;
          clearscreen();
          switch (choice2) {
            case 1:
              no_of_months = 1;
              break;
            case 2:
              no_of_months = 3;
              break;
            case 3:
              no_of_months = 6;
              break;
            case 4:
              no_of_months = 12;
              break;
            case 5:
              no_of_months = 60;
              break;
            default: {
              cout << FT_B_YEL "Invalid choice.... Try again....\n" FT_NRM;
            }
          }
          if (choice == 1 || choice == 2 || choice == 3 || choice == 4 ||
              choice == 5) {
            break;
          }
        }

        list<savingsAccount>::iterator it;
        it = savings_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        it->calculateInterest(no_of_months);
        break;
      }
      case 6: {
        cout << "CALCULATE AND UPDATE INTEREST\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(savings_acc_list, account_number)) == -1);
        if (tmp == false) {
          break;
        }
        list<savingsAccount>::iterator it;
        it = savings_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        it->update_interest();
        break;
      }
      case 7: {
        cout << "UPDATE TRANSACTION FEE\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(checking_acc_list, account_number)) == -1);

        if (tmp == false) {
          break;
        }
        cout << "Enter the new transaction fee: ";
        cin >> transaction_fee;
        list<checkingAccount>::iterator it;
        it = checking_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        if (it->update_transaction_fee(transaction_fee)) {
          cout << FT_B_GRN
               << "Transaction fee updated successfully!!! , New transaction "
                  "fee: "
               << transaction_fee << "%\n"
               << FT_NRM;
        } else {
          cout << FT_B_RED
               << "Transaction fee update failed ,Please enter valid "
                  "transaction fee\n"
               << FT_NRM;
        }

        break;
      }
      case 8: {
        cout << "PRINT TRANSACTION FEE\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(checking_acc_list, account_number)) == -1);

        if (tmp == false) {
          break;
        }

        list<checkingAccount>::iterator it;
        it = checking_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        it->print_transaction_fee();
        break;
      }
      case 9: {
        cout << "TRANSACT AND UPDATE\n";
        bool tmp = false;
        int pos;
        do {
          if (tmp) {
            cout << FT_B_RED
                 << "Sorry, Account number does not exists..(Enter 'q' to quit "
                    "to main menu) \n"
                 << FT_NRM;
          }
          tmp = true;
          cout << "Enter the account number: ";
          string str;
          cin >> str;
          if (str[0] == 'q') {
            tmp = false;
            break;
          }
          account_number = std::atoi(str.c_str());

        } while ((pos = check(checking_acc_list, account_number)) == -1);

        if (tmp == false) {
          break;
        }

        cout << "Enter the debit amount: ";
        cin >> debit_amount;
        list<checkingAccount>::iterator it;
        it = checking_acc_list.begin();
        for (int i = 0; i < pos; i++) {
          ++it;
        }
        if (it->debit(debit_amount)) {
          cout << FT_B_GRN << "Rs." << debit_amount
               << " debited successfully !!!, And transaction fee Rs."
               << it->get_transaction_fee() << " also debited \n"
               << FT_NRM;
        } else {
          cout << FT_B_RED << "Rs." << debit_amount
               << " debit failed, Please give valid amount \n"
               << FT_NRM;
        }

        break;
      }
      case 10:
        exit(0);
        break;
      default: {
        cout << "Invalid choice.... Try again....\n";
      }
    }
  }
}