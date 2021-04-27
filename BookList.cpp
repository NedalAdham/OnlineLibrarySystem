#include<iostream>
#include <stdlib.h>
using namespace std;
#include "BookList.h"
#include "Book.h"

 /* Book* books;
          int capacity;
          int booksCount;*/
//Copy Constructor...
    BookList::BookList(const BookList& anotherList){
        booksCount = anotherList.booksCount;
        capacity = anotherList.capacity;
        books = new Book[capacity];

        for(int i=0; i<booksCount; i++)
        {
            books[i]=anotherList.books[i];
        }

    };

//Default Constructor
    BookList::BookList(int capacity){
        this->capacity=capacity;
        books=new Book[capacity];
        booksCount=0;
    };


    Book&BookList:: searchBook(string name){
        int index;
        for(int i=0; i<booksCount; i++)
           {
            if(name == books[i].getTitle()){
                index = i;
                //If it's found, break loop and return it...
                break;
            }
    }
     return books[index];
};


    Book& BookList::searchBook(int id){
        return books[id-1];
    };

    void BookList::deleteBook(int id){
         for (int i = id-1 ; i<booksCount; i++)
        {
            books[i] = books[i+1];
        }
        booksCount = booksCount-1;

    };//delete a book


    Book BookList::getTheHighestRatedBook(){
        double MR=books[0].getrate(); //Maximum Rate
        int In=0; //Assume Maximum rate is the first element, intial value
        for(int i=1; i<booksCount; i++)
            {
                if (books[i].getrate()> MR){
                    MR=books[i].getrate();
                    In=i;
                }

            }
    return books[In];
 };


Book* BookList:: getBooksForUser(User& u){
        Book* b;
         int s=0;
         for (int i =0; i<booksCount; i++)
         {
             if (books[i].getAuthor()== u)
            {
                s++;
             }
         }

         if (s ==0){return nullptr;}

         else{
         b = new Book[s];
         for (int i =0; i<booksCount; i++)
         {
         if (books[i].getAuthor() == u){
             b[i] = books[i];
         }

         }}
         return b;
  };


    Book & BookList::operator [ ] (int position){
        return books[position];
    };

    int BookList:: getBooksCount(){
        return booksCount;
    }

ostream &operator <<( ostream &output, BookList &booklist ){
    for (int i=0; i<booklist.booksCount; i++){
       output << "========Books"<< i+1 << "info========" << endl;
        output << "Title: " << booklist.books[i].getTitle()<< endl;
        output << "ISBN: " << booklist.books[i].getISBN()<< endl;
        output << "Id: " << booklist.books[i].getId()<< endl;
        output << "Category: " << booklist.books[i].getCategory()<< endl;
        output << "Ave Rating: " << booklist.books[i].getrate()<< endl;
        output << "===========Author Info=============="<<endl;
        output << booklist.books[i].getAuthor()<< endl;

    }
       /*     for (int i=0; i<booklist.booksCount; i++){
                output << booklist.books[i];}*/
return output;
    }; //to display all books


   BookList::~BookList(){
       delete [] books;
   };

