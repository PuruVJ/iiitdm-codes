/*
17. (Subin) Consider 3 classes book, publisher, and details. In every base
class, all the data members have protected access and member fuctions have
protected access. The data members of 'details' class alone is public. publisher
derives book in private mode and details derives publisher in private mode. The
book class has a book_no and book_name data members. book_no is unique. It has
setBook, deleteBook and getBook member functions. The publisher class has
author_name and publisher_name data members. It has setInfo, deleteInfo, and
getInfo. The details class consists of number_of_pages and year_of_publication
as data members. It has setDetails, deleteDetails and getDetails as member
functions.  Assume there are 'n' books (n > 0) and the book details are stored
in an array of objects. Maintain proper boundary conditions and follow coding
best practices.

The menu is as follows:

1. Set Book Details
2. Display Book Details
3. Delete Book Details
4. Exit.

*/

#include <iostream>
using namespace std;

class Details {
 public:
  int number_of_pages;
  int year_of_publication;

 protected:
  void setDetails(int _numPages, int _year) {
    this->number_of_pages = _numPages;
    this->year_of_publication = _year;
  }

  void deleteDetails() {
    this->number_of_pages = -1;
    this->year_of_publication = -1;
  }

  void getDetails() {
    cout << "Number of Pages: " << this->number_of_pages << "\n";
    cout << "Year of Publication: " << this->year_of_publication << "\n";
  }
};

class Publisher : private Details {
 protected:
  string author_name;
  string publisher_name;

  void setInfo(string _authorName, string _publisherName) {
    this->author_name = _authorName;
    this->publisher_name = _publisherName;
  }

  void getInfo() {
    cout << "Publisher name: " << this->publisher_name << "\n";
    cout << "Author name: " << this->author_name << "\n";
  }

  void deleteInfo() {
    this->author_name = "";
    this->publisher_name = "";
  }
};

class Book : private Publisher {
 protected:
  string book_name;
  int book_no;

  void setBook(string _bookName, int _bookNo) {
    this->book_name = _bookName;
    this->book_no = _bookNo;
  }

 public:
  Book() {}

  Book(string _bookName, int _bookNo) {
    this->book_name = _bookName;
    this->book_no = _bookNo;
  }

  /**
   * NOTE TO TA: To print the books in the menu, I have to make this public or
   * it won't work at all.
   */
  void getBook() {
    cout << "Book name: " << this->book_name << "\n";
    cout << "Book No: " << this->book_no << "\n";
  }

  /**
   * NOTE TO TA: Same reason as above, have to access it somehow
   */
  void deleteBook() {
    this->book_name = "";
    this->book_no = 0;
  }
};

int main() {
  int numBooks;

  cout << "Number of books: ";
  cin >> numBooks;

  if (numBooks < 0) cout << "Number of books can't be less than 0";
  if (numBooks < 1) return 0;

  Book* books = new Book[numBooks];

  int choice;
  int bookPosition;

  while (true) {
    // Show the menu
    cout << "1. Set Book details\n";
    cout << "2. Display Book details\n";
    cout << "3. Delete Book details\n";
    cout << "4. Exit\n\n";

    // Ask for choice
    cout << "Enter the choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        // Ask for index
        cout << "Enter the position of book from 1 to " << numBooks << ": ";
        cin >> bookPosition;

        if (bookPosition < 1 || bookPosition > numBooks) {
          cout << "Number should be between 1 and " << numBooks << "\n";
          continue;
        }

        string bookName;
        cout << "Book name: ";
        cin >> bookName;

        int bookNo;
        cout << "Book Number: ";
        cin >> bookNo;

        books[bookPosition - 1] = *(new Book(bookName, bookNo));

        cout << "Done\n\n";

        break;
      }

      case 2: {
        // Ask for index
        cout << "Enter the position of book from 1 to " << numBooks << ": ";
        cin >> bookPosition;

        if (bookPosition < 1 || bookPosition > numBooks) {
          cout << "Number should be between 1 and " << numBooks << "\n";
          continue;
        }

        books[bookPosition - 1].getBook();
        cout << endl;

        break;
      }

      case 3: {
        // Ask for index
        cout << "Enter the position of book from 1 to " << numBooks << ": ";
        cin >> bookPosition;

        if (bookPosition < 1 || bookPosition > numBooks) {
          cout << "Number should be between 1 and " << numBooks << "\n";
          continue;
        }

        books[bookPosition - 1].deleteBook();
        cout << endl;

        break;
      }

      case 4: {
        exit(0);
      }

      default: {
        cout << "Please enter the choice between 1-4\n";
        break;
      }
    }

    cout << endl;
  }

  return 0;
}