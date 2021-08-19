// Group No. : P10
// LOGIC - 1

#include <math.h>

#include <climits>
#include <iostream>
using namespace std;

// creating a class
class Operation {
  int size;
  int* num = new int[size];

 public:
  void array_creation();
  void find_max();
  void find_min();
  void find_secondmax();
  void find_secondmin();
};

void Operation::array_creation() {
  cout << "Enter number of integers in the array : ";
  cin >> size;

  int i;
  cout << "Enter integers : ";
  for (i = 0; i < size; i++) {
    cin >> num[i];
  }
}

void Operation::find_max() {
  int i;
  int maximum = num[0];

  for (i = 1; i < size; i++) {
    maximum = max(maximum, num[i]);
  }
  cout << " MAX = " << maximum << endl;
}

void Operation::find_min() {
  int i;
  int minimum = num[0];

  for (i = 1; i < size; i++) {
    minimum = min(minimum, num[i]);
  }
  cout << " MIN = " << minimum << endl;
}

void Operation::find_secondmax() {
  int i;
  int maximum = INT_MIN;
  int secondmaximum = INT_MIN;

  for (i = 0; i < size; i++) {
    if (num[i] > maximum) {
      secondmaximum = maximum;
      maximum = num[i];
    }

    if (num[i] < maximum && num[i] > secondmaximum) {
      secondmaximum = num[i];
    }
  }

  cout << "Second MAX = " << secondmaximum << endl;
}

void Operation::find_secondmin() {
  int i;
  int minimum = INT_MAX;
  int secondminimum = INT_MAX;

  for (i = 0; i < size; i++) {
    if (num[i] < minimum) {
      secondminimum = minimum;
      minimum = num[i];
    }

    if (num[i] > minimum && num[i] < secondminimum) {
      secondminimum = num[i];
    }
  }

  cout << "Second MIN = " << secondminimum << endl;
}

int main() {
  Operation op1;
  op1.array_creation();
  op1.find_max();
  op1.find_min();
  op1.find_secondmax();
  op1.find_secondmin();

  return 0;
}