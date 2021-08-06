#include <iostream>
using namespace std;

#include "queue.cpp"

int main() {
  Queue printerQueue;

  // Print Menu
  cout << "Choose from the list below: " << endl;

  cout << "1. Add to Print Queue" << endl;
  cout << "2. Current Job" << endl;
  cout << "3. Execute a Job" << endl;
  cout << "4. Display Jobs" << endl;
  cout << "5. Exit" << endl << endl;

  while (true) {
    int choice;

    cout << "Enter the number of the task: ";
    cin >> choice;

    if (choice == 1) {
      int jobID;

      cout << "Enter the Job ID as an integer: ";
      cin >> jobID;

      printerQueue.enqueue(jobID);

    } else if (choice == 2) {
      if (printerQueue.isEmpty()) {
        cout << "No job in queue" << endl;
        continue;
      }

      cout << "Current job is " << printerQueue.peek() << endl;

    } else if (choice == 3) {
      int val = printerQueue.dequeue();

      if (val == INT8_MIN) {
        // Queue was empty
        cout << "No jobs in the queue" << endl;
        continue;
      }

      cout << "Job #" << val << " executed successfully" << endl;

    } else if (choice == 4) {
      cout << "Job IDs: ";
      printerQueue.display();
      cout << endl;

    } else if (choice == 5) {
      cout << "Exit program" << endl;
      break;

    } else {
      cout << "Invalid option. Please enter a number from the menu specified "
              "above"
           << endl;
    }
  }

  return 0;
}