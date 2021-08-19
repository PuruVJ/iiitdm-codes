#include <iostream>
using namespace std;

class Queue {
 private:
  int front = 0;
  int rear = -1;
  int array[5];

  int count = 0;

 public:
  void enqueue(int);
  int dequeue();

  int peek() { return array[front]; }

  void display() {
    if (count == 0) {
      cout << "No jobs in queue";
      return;
    }
    for (int i = 0; i < count; i++) {
      cout << array[(front + i) % 5] << " ";
    }
  }

  bool isFull() { return count == 5; }

  bool isEmpty() { return count == 0; }
};

void Queue::enqueue(int value) {
  if (isFull()) {
    cout << "Queue is full" << endl;
    return;
  }

  rear = (rear + 1) % 5;
  array[rear] = value;
  count++;
}

int Queue::dequeue() {
  if (isEmpty()) return INT8_MIN;

  int item = array[front];

  front = ++front % 5;
  count--;

  return item;
}

#include <iostream>
using namespace std;

int main() {
  Queue jobQueue;

  cout << "Choose the action: " << endl;  // Task menu
  cout << "1 to Add to Print Queue" << endl;
  cout << "2 to View current Job" << endl;
  cout << "3 to Execute current Job" << endl;
  cout << "4 to Display Jobs" << endl;
  cout << "5 to Exit" << endl << endl;

  while (true) {
    int choice;
    cout << "Enter the number of the task: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        int jobID;
        cout << "Enter the Job ID : ";
        cin >> jobID;
        jobQueue.enqueue(jobID);
      } break;
      case 2: {
        if (jobQueue.isEmpty()) {
          cout << "No job in queue" << endl;
          continue;
        }
        cout << "Current job is " << jobQueue.peek() << endl;
      } break;

      case 3: {
        int val = jobQueue.dequeue();
        if (val == INT8_MIN) {
          // Queue was empty
          cout << "No jobs are there in the queue" << endl;
          continue;
        }

        cout << "Job " << val << " executed successfully" << endl;
      } break;
      case 4: {
        cout << "Job IDs: ";
        jobQueue.display();
        cout << endl;
      } break;
      case 5:
        cout << "Terminating the program" << endl;
        exit(1);
      default:
        cout << "Enter a valid number" << endl;
    }
  }
  return 0;
}