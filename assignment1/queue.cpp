#include <iostream>
using namespace std;

class Queue {
 private:
  int front = 0;
  int rear = -1;
  int arr[5];

  int count = 0;

 public:
  void enqueue(int);
  int dequeue();

  int peek() { return arr[front]; }

  void display() {
    if (count == 0) {
      cout << "No jobs in queue";
      return;
    }

    for (int i = 0; i < count; i++) {
      cout << arr[(front + i) % 5] << " ";
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
  arr[rear] = value;
  count++;
}

int Queue::dequeue() {
  if (isEmpty()) return INT8_MIN;

  int item = arr[front];

  front = ++front % 5;
  count--;

  return item;
}
