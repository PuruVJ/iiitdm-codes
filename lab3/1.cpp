#include <iostream>
using namespace std;

class Node {
 public:
  int number;
  Node *next;

 public:
  Node() {
    number = 0;
    next = NULL;
  }

  Node *insertNode(Node *head, int num) {
    Node *temp = new Node();

    temp->number = num;
    temp->next = NULL;

    if (head == NULL) {
      head = temp;
      return head;
    }

    if (head->number > num) {
      temp->next = head;
      head = temp;
      return head;
    }

    Node *save = head;
    for (save = head; save->next != NULL; save = save->next) {
      if (save->next->number > num) {
        Node *temp1 = save->next;
        save->next = temp;
        temp->next = temp1;
        return head;
      }
    }
    save->next = temp;
    return head;
  }

  /**
   * @param {Node} *head
   * @param {int} position - Starts from 1
   */
  Node *deleteNode(Node *head, int position) {
    if (head == NULL) {
      cout << "List is Empty.\n";
      return head;
    }

    if (head->next == NULL) {
      if (position == 1) {
        head = NULL;
        return head;
      }

      cout << "The node is not in the list.\n";
      return head;
    }

    if (position == 1) {
      head = head->next;
      return head;
    }

    Node *checkpoint = head;
    Node *delNode = NULL;

    int i = 1;
    for (; head->next != NULL && i <= position; i++) {
      if (i == position - 1) delNode = head;
      head = head->next;
    }

    if (i < position) {
      cout << "The node is not in the list.\n";
    } else {
      cout << "The node deleted.\n";
      delNode->next = delNode->next->next;
    }

    return checkpoint;
  }

  void display(Node *head) {
    cout << "The list is: ";

    for (Node *checkpoint = head; checkpoint != NULL;
         checkpoint = checkpoint->next) {
      cout << checkpoint->number << " ";
    }

    cout << endl;
  }

  Node *mergeLists(Node *head1, Node *head2) {
    Node *ptr1 = head1, *ptr2 = head2;
    Node *temp = new Node();
    Node *ptr3 = temp;

    while (ptr2 != NULL) {
      ptr3->next = ptr2;
      ptr2 = ptr2->next;
      ptr3 = ptr3->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
      if (ptr1->number < ptr2->number) {
        ptr3->next = ptr1;

        ptr1 = ptr1->next;

      } else {
        ptr3->next = ptr2;

        ptr2 = ptr2->next;
      }

      ptr3 = ptr3->next;
    }

    while (ptr1 != NULL) {
      ptr3->next = ptr1;

      ptr1 = ptr1->next;

      ptr3 = ptr3->next;
    }

    head1 = temp->next;
    head2 = temp->next;

    cout << "\n\n\n  The lists have been merged " << endl;

    return head1;
  }
};

int main() {
  Node n;
  Node *head1 = NULL;
  Node *head2 = NULL;

  int choice = 0;

  int num = 0;

  int listNum = 0;

  cout << "\n\n1. Insertion \n";
  cout << "2. Deletion at a particular position \n";
  cout << "3. Display \n";
  cout << "4. Merging of the sorted arrays \n";
  cout << "5. Exit \n\n";

  while (true) {
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "\nWhich list to insert to: ";
      cin >> listNum;

      if (listNum == 1) {
        cout << "Enter Number: \n";
        cin >> num;
        head1 = n.insertNode(head1, num);
      } else if (listNum == 2) {
        cout << "Enter Number: \n";
        cin >> num;
        head2 = n.insertNode(head2, num);
      } else {
        cout << "Sorry incorrect.\n";
      }

    } else if (choice == 2) {
      cout << "\nWhich list?";
      cin >> listNum;

      if (listNum == 1) {
        cout << "Enter Position for the deleteion to occur: \n";
        cin >> num;

        n.deleteNode(head1, num);

      } else if (listNum == 2) {
        cout << "Enter Position for the deleteion to occur: \n";
        cin >> num;

        n.deleteNode(head2, num);
      } else {
        cout << "Sorry incorrect.\n";
      }

    } else if (choice == 3) {
      cout << "\nWhich list?";
      cin >> listNum;

      if (listNum == 1) {
        head1->display(head1);
      } else if (listNum == 2) {
        head2->display(head2);
      } else {
        cout << "Sorry incorrect.\n";
      }

    } else if (choice == 4) {
      head1 = n.mergeLists(head1, head2);
      head2 = head1;

    } else if (choice == 5) {
      exit(0);

    } else {
      cout << "Sorry, incorrect.";
    }
  }

  return 0;
}