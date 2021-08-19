// Group No. : P10
// LOGIC - 3

#include <iostream>
using namespace std;

class Operation {
  int size;
  int* num = new int[size];
  int max;
  int min;

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
  int i;
  if (size % 2 == 1) {
    max = num[0];
    i = 1;
  } else {
    if (num[0] < num[1]) {
      max = num[1];

    } else {
      max = num[0];
    }
    i = 2;
  }

  while (i < size) {
    if (num[i] < num[i + 1]) {
      if (num[i + 1] > max) {
        max = num[i + 1];
      }

    } else {
      if (num[i] > max) {
        max = num[i];
      }
    }
    i = i + 2;
  }

  cout << "MAX = " << max << endl;
}

void Operation::find_min() {
  int i;

  if (size % 2 == 1) {
    min = num[0];
    i = 1;
  } else {
    if (num[0] < num[1]) {
      min = num[0];
    } else {
      min = num[1];
    }
    i = 2;
  }

  while (i < size) {
    if (num[i] < num[i + 1]) {
      if (num[i] < min) {
        min = num[i];
      }
    } else {
      if (num[i + 1] < min) {
        min = num[i + 1];
      }
    }
    i = i + 2;
  }

  cout << "MIN = " << min << endl;
}

void Operation::find_secondmax() {
  // now we already know max in the array
  // we will delete that index element from the array
  // and again using the above logic we will find second max

  // first of all counting total occurences of max in the array
  int count = 0;
  int i;
  for (i = 0; i < size; i++) {
    if (num[i] == max) {
      count++;
    }
  }

  // Search max in array

  int smax;
  while (count-- > 0) {
    for (i = 0; i < size; i++) {
      if (num[i] == max) break;
    }

    // If max found in array
    if (i < max) {
      // reduce size of array
      size = size - 1;
      for (int j = i; j < size; j++) num[j] = num[j + 1];
    }
  }

  // now finding max in this new array
  if (size % 2 == 1) {
    smax = num[0];
    i = 1;
  } else {
    if (num[0] < num[1]) {
      smax = num[1];

    } else {
      smax = num[0];
    }
    i = 2;
  }

  while (i < size) {
    if (num[i] < num[i + 1]) {
      if (num[i + 1] > smax) {
        smax = num[i + 1];
      }

    } else {
      if (num[i] > smax) {
        smax = num[i];
      }
    }
    i = i + 2;
  }

  cout << "SECOND MAX = " << smax << endl;
}

void Operation::find_secondmin() {
  // similar to how we found out second max, we will find second min
  int count = 0;
  int i;
  for (i = 0; i < size; i++) {
    if (num[i] == min) {
      count++;
    }
  }

  int smin;
  while (count-- > 0) {
    for (i = 0; i < size; i++) {
      if (num[i] == min) break;
    }

    // If min found in array
    if (i > min) {
      // reduce size of array
      size = size - 1;
      for (int j = i; j < size; j++) num[j] = num[j + 1];
    }
  }

  // now finding min in this new reduced array
  if (size % 2 == 1) {
    smin = num[0];
    i = 1;
  } else {
    if (num[0] < num[1]) {
      smin = num[0];
    } else {
      smin = num[1];
    }
    i = 2;
  }

  while (i < size) {
    if (num[i] < num[i + 1]) {
      if (num[i] < smin) {
        smin = num[i];
      }
    } else {
      if (num[i + 1] < smin) {
        smin = num[i + 1];
      }
    }
    i = i + 2;
  }

  cout << "Second MIN = " << smin << endl;
}

int main() {
  Operation op3;
  op3.array_creation();
  op3.find_max();
  op3.find_min();
  op3.find_secondmax();
  op3.find_secondmin();

  return 0;
}