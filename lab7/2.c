#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *Top;
  int size;
} Stack;

typedef struct Queue {
  Node *front;
  Node *rear;
  int Max_Size;
  int size;
} Queue;

/** Core Functions defined here */

void initializeStack(Stack *stack) {
  stack->Top = NULL;
  stack->size = 0;
}

void initializeQueue(Queue *queue, int max) {
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0L;
  queue->Max_Size = max;
}

void freeStack(Stack *stack) {
  Node *temp;

  while (stack->Top != NULL) {
    temp = stack->Top->next;
    free(stack->Top);
    stack->Top = temp;
  }
}

void freeQueue(Queue *queue) {
  Node *temp;
  while (queue->front != NULL) {
    temp = queue->front;

    if (queue->front == queue->rear) {
      queue->rear = NULL;
    }
    queue->front = queue->front->next;

    free(temp);
  }
}

Node *peekStack(Stack *stack) {
  if (stack->size == 0) {
    return NULL;
  }

  else {
    return stack->Top;
  }
}

Node *peekQueue(Queue *queue) {
  if (queue->size == 0) {
    return NULL;
  }

  else {
    return queue->front;
  }
}

void push(Stack *stack, int data) {
  Node *new_tray;

  new_tray = (Node *)malloc(sizeof(Node));
  if (new_tray == NULL) {
    printf("\nOut of Memory! Program Exit!\n");
    freeStack(stack);
    exit(0);
  }
  new_tray->data = data;
  new_tray->next = stack->Top;

  stack->size++;

  new_tray->key = stack->size;
  stack->Top = new_tray;
}

int pop(Stack *stack) {
  Node *temp;

  if (stack->Top == NULL) {
    printf("\nUNDERFLOW! Program Exit!");
    exit(0);
  }

  int rtr;

  rtr = stack->Top->data;

  temp = stack->Top;
  stack->Top = stack->Top->next;
  stack->size--;

  free(temp);

  return rtr;
}

void enqueue(Queue *queue, int d) {
  Node *temp;

  temp = (Node *)malloc(sizeof(Node));

  if (temp == NULL) {
    printf("Insufficient Memory! Program Terminated!");
    freeQueue(queue);
    exit(0);
  }

  if (queue->size == queue->Max_Size) {
    printf("Parking Lot FULL!");
    return;
  }

  temp->data = d;
  temp->next = NULL;

  queue->size = (queue->size) + 1;

  temp->key = queue->size;

  if (queue->rear == NULL) {
    queue->front = temp;
    queue->rear = temp;
  }

  else {
    queue->rear->next = temp;
    queue->rear = temp;
  }
}

int dequeue(Queue *queue) {
  Node *temp;

  if (queue->front == NULL) {
    printf("\nParking Lot is Empty!\n");
    return -1;
  }

  int rtr;
  rtr = queue->front->data;
  queue->size -= 1;
  temp = queue->front;

  if (queue->front == queue->rear) {
    queue->rear = NULL;
  }

  queue->front = queue->front->next;

  free(temp);

  return rtr;
}

/** Our program related functions here */

void addCarToFront(Queue *queue, int k, int d) {
  Node *temp = malloc(sizeof(Node));

  if (temp == NULL) {
    printf("\nInsufficient Memory! Program Terminated!\n");
    freeQueue(queue);
    exit(0);
  }

  if (queue->size == queue->Max_Size) {
    printf("\nParking Lot FULL!\n");
    return;
  }

  temp->key = k;
  temp->data = d;

  queue->size = (queue->size) + 1;

  if (queue->front == NULL) {
    temp->next = NULL;
    queue->front = temp;
    queue->rear = temp;
  } else {
    temp->next = queue->front;
    queue->front = temp;
  }
}

void removeCarFromQueue(Queue *queue, int k) {
  if (k > queue->size) return;

  Stack temp;

  initializeStack(&temp);

  k--;

  for (; k > 0; k--) push(&temp, dequeue(queue));

  dequeue(queue);
  printf("\nCar removed!!\n");

  int x;

  while (temp.Top != NULL) {
    x = temp.Top->key;
    addCarToFront(queue, x, pop(&temp));
  }
}

void printCarQueue(Queue *queue) {
  for (Node *ptr = queue->front; ptr != NULL; ptr = ptr->next)
    printf(" %d [%d] ", ptr->data, ptr->key);
}

void main() {
  Queue queue;

  int max;

  printf("Enter Max Size of Parking Lot : ");
  scanf("%d", &max);

  printf("\n\n");
  initializeQueue(&queue, max);

  int data;
  char choice = '1';
  int k;

  printf("Select one of the following :\n\n");
  printf("\n1. Press 'e' to enter a new car to the Parking from the REAR end.");
  printf(
      "\n2. Press 'l' to leave a new car from the Parking from the FRONT end.");
  printf("\n3. Press 's' to show the cars currently present in the Parking.");
  printf(
      "\n4. Press 'r' to Remove a car from a given Location (K) in the "
      "parking.");
  printf("\n5. Press 'q' to Quit.\n\n");

  while (!(choice == 'q' || choice == 'Q')) {
    printf("\n\nEnter Your Choice:- ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
      printf("\nEnter Car No: ");
      scanf(" %d", &data);
      enqueue(&queue, data);
    }

    if (choice == 'l' || choice == 'L')
      if (peekQueue(&queue) != NULL)
        printf("New Car : Car No %d", dequeue(&queue));

    if (choice == 's' || choice == 'S') printCarQueue(&queue);

    if (choice == 'r' || choice == 'R') {
      printf("\nEnter Car No to remove : ");
      scanf(" %d", &k);
      removeCarFromQueue(&queue, k);
    }
  }
}