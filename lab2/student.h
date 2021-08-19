#include <iostream>
using namespace std;

class Student {
 private:
  string name;
  string roll_no;
  int webdev_marks;
  int math_marks;
  int server_marks;
  int golang_marks;
  int nosql_marks;

 public:
  Student() {
    name = "";
    roll_no = "";
    webdev_marks = 0;
    math_marks = 0;
    server_marks = 0;
    golang_marks = 0;
    nosql_marks = 0;
  }

  Student(string _name, string _roll) {
    name = _name;
    roll_no = _roll;
    webdev_marks = 0;
    math_marks = 0;
    server_marks = 0;
    golang_marks = 0;
    nosql_marks = 0;
  }

  void setMarks(string a, string b, int c, int d, int e, int f, int g) {
    name = a;
    roll_no = b;
    webdev_marks = c;
    math_marks = d;
    server_marks = e;
    golang_marks = f;
    nosql_marks = g;
  }

  void displayMarks() {
    cout << "\n Name : " << name;
    cout << "\n Roll No : " << roll_no;
    cout << "\n Web Dev Marks : " << webdev_marks;
    cout << "\n Maths Marks : " << math_marks;
    cout << "\n Server Marks : " << server_marks;
    cout << "\n Golang Marks : " << golang_marks;
    cout << "\n NoSQL marks : " << nosql_marks << endl;
  }
};
