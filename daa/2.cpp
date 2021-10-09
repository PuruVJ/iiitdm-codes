/**
 * Complexity would be O(n^2)
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int divideArr(int* arr, int low, int high, int* lp) {
  if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);

  int lowNext = low + 1;
  int highPrevious = high - 1;
  int lowNextCopy = low + 1;

  int leftPivot = arr[low];
  int rightPivot = arr[high];

  while (lowNextCopy <= highPrevious) {
    // if elements are less than the left pivot
    if (arr[lowNextCopy] < leftPivot) {
      swap(&arr[lowNextCopy], &arr[lowNext]);
      lowNext++;
    } else if (arr[lowNextCopy] >= rightPivot) {
      // if elements are greater than or equal
      // to the right pivot
      while (arr[highPrevious] > rightPivot && lowNextCopy < highPrevious)
        highPrevious--;

      swap(&arr[lowNextCopy], &arr[highPrevious]);

      highPrevious--;

      if (arr[lowNextCopy] < leftPivot) {
        swap(&arr[lowNextCopy], &arr[lowNext]);
        lowNext++;
      }
    }

    lowNextCopy++;
  }

  lowNext--;
  highPrevious++;

  // bring pivots to their appropriate positions.
  swap(&arr[low], &arr[lowNext]);
  swap(&arr[high], &arr[highPrevious]);

  // returning the indices of the pivots.
  *lp = lowNext;  // because we cannot return two elements
  // from a function.

  return highPrevious;
}

void quickSortWithTwoPivots(int* arr, int low, int high) {
  if (low < high) {
    int leftPivot, rightPivot;

    rightPivot = divideArr(arr, low, high, &leftPivot);

    quickSortWithTwoPivots(arr, low, leftPivot - 1);
    quickSortWithTwoPivots(arr, leftPivot + 1, rightPivot - 1);
    quickSortWithTwoPivots(arr, rightPivot + 1, high);
  }
}

int main() {
  int n;
  cout << "Number of elements in array: ";
  cin >> n;

  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  quickSortWithTwoPivots(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}