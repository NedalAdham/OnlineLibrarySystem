#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include "Book.h"
#include<iostream>
#include <stdlib.h>
using namespace std;

class BookList{
    private:
          Book* books;
          int capacity;
          int booksCount;
    public:
        BookList(const BookList& anotherList);
        BookList(int capacity);
        Book& searchBook(string name);
        Book& searchBook(int id);
        void deleteBook(int id); //delete a book
        Book getTheHighestRatedBook();
        Book* getBooksForUser(User& u); // get all books of this author
        Book & operator [ ] (int position);
        int getBooksCount();
        friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
        ~BookList();
    };


#endif // BOOKLIST_H_INCLUDED
