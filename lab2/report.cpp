#include <iostream>

#include "student.h"

int main() {
  Student student1, student2, student3;

  Student student4("who", "is"), student5("the", "batman");

  student1.setMarks("Diana Prince", "1101", 94, 90, 56, 9, 100);
  student2.setMarks("Barry Allen", "1312", 90, 100, 47, 40, 100);
  student3.setMarks("Gordon", "1231", 89, 97, 10, 95, 100);

  student4.setMarks("Bruce Wayne", "0001", 100, 100, 100, 100, 100);
  student5.setMarks("Clark Kent", "0002", 76, 91, 53, 2, 1);

  student1.displayMarks();
  student2.displayMarks();
  student3.displayMarks();
  student4.displayMarks();
  student5.displayMarks();

  return 0;
}