// Group No. : P10
// LOGIC - 2

#include <math.h>

#include <climits>
#include <iostream>
using namespace std;

class Operation {
  int size;
  int* num = new int[size];
  int half = floor(size / 2);

 public:
  void array_creation();
  void find_max();
  void find_min();
  void find_secondmax();
  void find_secondmin();
};

void Operation::array_creation() {
  cout << "Enter no. of integers in an array : ";
  cin >> size;
  cout << "Enter integers : ";
  int i;
  for (i = 0; i < size; i++) {
    cin >> num[i];
  }
}

void Operation::find_max() {
  // dividing the array into half
  // and finding max. in respective halves and then comapring them
  int max1, max2;
  max1 = num[0];
  max2 = num[half];
  for (int i = 0; i < half; i++) {
    if (num[i] > max1) {
      max1 = num[i];
    }
  }

  for (int i = half; i < size; i++) {
    if (num[i] > max2) {
      max2 = num[i];
    }
  }

  if (max1 > max2) {
    cout << "MAX = " << max1 << endl;
  } else {
    cout << "MAX = " << max2 << endl;
  }
}

void Operation::find_min() {
  // dividing the array into half
  // and finding min. in respective halves and then comapring them
  int min1, min2;
  min1 = num[0];
  min2 = num[half];
  for (int i = 0; i < half; i++) {
    if (num[i] < min1) {
      min1 = num[i];
    }
  }

  for (int i = half; i < size; i++) {
    if (num[i] < min2) {
      min2 = num[i];
    }
  }

  if (min1 < min2) {
    cout << "MIN = " << min1 << endl;
  } else {
    cout << "MIN = " << min2 << endl;
  }
}

void Operation::find_secondmax() {
  int max1 = INT_MIN;
  int smax1 = INT_MIN;
  int i;
  for (i = 0; i < half; i++) {
    if (num[i] > max1) {
      smax1 = max1;
      max1 = num[i];
    }

    if (num[i] < max1 && num[i] > smax1) {
      smax1 = num[i];
    }
  }

  int max2 = INT_MIN;
  int smax2 = INT_MIN;
  for (i = half; i < size; i++) {
    if (num[i] > max2) {
      smax2 = max2;
      max2 = num[i];
    }

    if (num[i] < max2 && num[i] > smax2) {
      smax2 = num[i];
    }
  }

  if (smax1 > smax2) {
    cout << "Second MAX = " << smax1 << endl;
  } else {
    cout << "Second MAX = " << smax2 << endl;
  }
}

void Operation::find_secondmin() {
  int min1 = INT_MAX;
  int smin1 = INT_MAX;
  int i;
  for (i = 0; i < half; i++) {
    if (num[i] < min1) {
      smin1 = min1;
      min1 = num[i];
    }

    if (num[i] > min1 && num[i] < smin1) {
      smin1 = num[i];
    }
  }

  int min2 = INT_MAX;
  int smin2 = INT_MAX;
  for (i = half; i < size; i++) {
    if (num[i] < min2) {
      smin2 = min2;
      min2 = num[i];
    }

    if (num[i] > min2 && num[i] < smin2) {
      smin2 = num[i];
    }
  }

  if (smin1 < smin2) {
    cout << "Second MIN = " << smin1 << endl;
  } else {
    cout << "Second MIN = " << smin2 << endl;
  }
}

int main() {
  Operation op2;
  op2.array_creation();
  op2.find_max();
  op2.find_min();
  op2.find_secondmax();
  op2.find_secondmin();

  return 0;
}
