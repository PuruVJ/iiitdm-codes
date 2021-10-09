/**
 * Complexity analysis
 * Starting with `main` function, we identify bottlenecks that could cause
 * complexity to increase.
 * We have a for loop inside `main`. That bumps up the complexity for now to
 * O(n). Then we call `decToBin` inside the loop.
 *
 * Now assessing `decToBin` implementation:
 * `decToBin` has 2 loops in it, but these are independant of each other. And
 * both loops iterate through the sourceset linearly, meaning the final
 * complexity of this whole function would be O(n).
 *
 * This makes the complexity of current program O(n^2) for now.
 *
 * We call `binToDec` too, which is similar to complexity of `decToBin`, but
 * called independantly, so the complexity of whole program stays O(n^2)
 *
 *
 *
 *
 *
 * FINAL ANSWER: O(n^2)
 */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Binary {
 public:
  void printBinary(int value, int length) {
    for (int i = (length - 1); i >= 0; i--) cout << ((value >> i) & 1 ? 1 : 0);
  }

  int* decToBin(int value, int length) {
    int* binaryArr = new int[length];

    for (int i = 0; i < length; i++) binaryArr[i] = (value >> i) & 1 ? 1 : 0;

    int start = 0;
    int end = length - 1;

    while (start < end) {
      int temp = binaryArr[start];
      binaryArr[start] = binaryArr[end];
      binaryArr[end] = temp;

      start++;
      end--;
    }

    return binaryArr;
  }

  int binToDec(int* arr) {
    int decimalValue = 0;
    int base = 1;

    for (int i = 16; i >= 0; i--) {
      decimalValue += arr[i] * base;
      base *= 2;
    }

    return decimalValue;
  }

  // takes two arrays and subtracts the values
  // at each index from one another,
  // returning these values in an array
  int* subtractArrayFromArray(int* arr1, int* arr2) {
    int* arr[8];
    int a;
    int b;

    for (int i = 0; i < 8; i++) {
      a = arr1[i];
      b = arr2[i];
      arr[i] = &a - b;
    }

    return *arr;
  }

  // takes an int and two arrays containing bits,
  // then mreges the three into one array and returns this array
  int* mergeArrays(int arr1[], int arr2[], int c) {
    int* arr = new int[17];
    arr[0] = c;

    for (int i = 1; i < 9; i++) arr[i] = arr1[i - 1];

    for (int i = 9; i < 17; i++) arr[i] = arr2[i - 9];

    return arr;
  }
};

int main() {
  Binary binOps;

  int multiplier;
  int multiplicand;
  int c = 0;
  int accumulator = 0;

  // scanning for user input and validating it
  // ensuring that the numbers are ints between 0 and 255
  cout << "multiplicand: ";
  cin >> multiplicand;

  cout << "multiplier: ";
  cin >> multiplier;

  // store original values for output at the end
  int multiplierHold = multiplier;
  int multiplicandHold = multiplicand;

  // preliminary outputs
  cout << "\nc and acc set to 0\n";
  cout << "mq set to multiplier    =  " << multiplier << " decimal and ";
  binOps.printBinary(multiplier, 8);
  cout << " binary\n";
  cout << "mdr set to multiplicand =  " << multiplicand << " decimal and ";
  binOps.printBinary(multiplicand, 8);
  cout << " binary\n";

  // creating binary array version of register values
  int* accumulatorArr = binOps.decToBin(accumulator, 8);
  int* multiplierArr = binOps.decToBin(multiplier, 8);
  int* multiplicandArr = binOps.decToBin(multiplicand, 8);

  // loops 8 times, printing out one step each time
  for (int step = 1; step < 9;) {
    accumulatorArr = binOps.decToBin(accumulator, 8);

    multiplierArr = binOps.decToBin(multiplier, 8);

    // prints multiplicand in binary
    multiplicandArr = binOps.decToBin(multiplicand, 8);

    // checks whether addition should be performed in this step
    // by checking the least significant bit
    if (multiplierArr[7] == 1) accumulator += multiplicand;

    // set the carry value
    if (accumulator >= 256) {
      c = 1;
      accumulator -= 256;
    }

    // re-instantiate register value arrays
    // to accommodate accumulator addition
    int* accumulatorArr = binOps.decToBin(accumulator, 8);
    int* multiplierArr = binOps.decToBin(multiplier, 8);
    int* multiplicandArr = binOps.decToBin(multiplicand, 8);

    // merge acc, mq, and carry into one array for printing
    int* full_arr = binOps.mergeArrays(accumulatorArr, multiplierArr, c);

    // convert merged binary array to decimal for processing
    int full_int = binOps.binToDec(full_arr);
    full_int >>= 1;
    full_arr = binOps.decToBin(full_int, 17);

    // fix leading bits in mq and acc after shift
    multiplier >>= 1;
    if (accumulatorArr[7] == 1) multiplier += 128;

    multiplierArr = binOps.decToBin(multiplier, 8);

    accumulator >>= 1;

    if (c == 1) {
      accumulator += 128;
      c = 0;
    }

    accumulatorArr = binOps.decToBin(accumulator, 8);

    // increment step counter
    step++;

    // after last step, print the multiplication check
    if (step == 9) {
      cout << "\n\n Results: \n\n";
      // print product in binary and decimal
      for (int i = 1; i < 17; i++) cout << full_arr[i];

      cout << "        " << (multiplierHold * multiplicandHold) << "\n";
    }
  }

  return 0;
}