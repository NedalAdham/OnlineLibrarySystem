#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

using namespace std;

int main()
{
    BookList booklist(10); //as default
    UserList userlist(10);

    //Program Choices
    while (true){
       int In_1;
       cout << "Select one of the following choices: "<< endl<<
       "1- Books Menu" <<endl << "2- Users Menu" << endl << "3- Exit" <<endl;
       cin >> In_1;

        //if Book Menu is chosen
       if(In_1==1){
         int s;
         cout << "How many books will be added?" << endl;
         cin>> s;
        BookList BL(s);

         //Loop of appearing Book menu
         while (true){
            int In_2;
            cout << "1- Create a book and add it to the list"<<endl<< "2- Search for a book"<< endl<<
            "3- Display al1 books (with book rating)"<< endl << "4- Get the hihest rating book" << endl
            << "5- Get all books of a user" <<endl<< "6- Copy the current Book List to a new Book List and switch to it" <<
            endl << "7- Back to the main menu" << endl;
            cin >> In_2;

            //When Create a book is chosen
            if(In_2 == 1){
                    Book b1;
                    cout<<"Enter the user information in this order "<<endl
                    <<"Title ISBN Category (Space separated)"<<endl;
                    cin >> b1;
                    BL[BL.getBooksCount()] = b1;

                    int In_3;
                    cout << "1- Assign author" << endl <<"2- Continue" << endl;
                    cin >> In_3;
                    while (true){
                        if (In_3==1){
                            cout << "Enter ID" << endl;
                            int In_ID;
                            cin >> In_ID;
                            b1.setAuthor(userlist.searchUser(In_ID));
                            break;

                        }
                        else if (In_3==2){
                            break;
                        }
                    }

                    }

                else if (In_2 == 2)
                {
                    cout << "SEARCH FOR A BOOK\n1- Search by name\n2- Search by id\n3- Return to books menu\n";
                    int book2choose;
                    cin >> book2choose;
                    if (book2choose == 1)
                    {
                        cout << "Enter Name\n";
                        string namesearch;cin >> namesearch;
                        Book book = BL.searchBook(namesearch);cout << book;
                        cout << "1- Update author\n"
                                "2- Update name\n"
                                "3- Update Category\n"
                                "4- Delete Book\n"
                                "5- Rate book"
                                "\n6- Get back to books menu\n";
                        int book3choose;
                        cin >> book3choose;
                    while(true){
                        if (book3choose == 1)
                        {
                            User new_User;
                            cout << "Enter new Author ID:\n";
                            book.setAuthor(new_User);
                            break;
                        }
                        else if (book3choose== 2)
                        {
                            cout << "Enter New Name:\n";
                            string name;
                            cin >> name;
                            book.setTitle(name);
                            break;
                        }
                        else if (book3choose == 3)
                        {
                            cout << "Enter Category:\n";
                            string catg;
                            cin >> catg;
                            book.setCategory(catg);
                            break;
                        }
                        else if (book3choose == 4)
                        {
                            cout << "Enter Id:\n";
                            int id;
                            cin >> id;
                            BL.deleteBook(id);
                            break;
                        }
                        else if (book3choose == 5)
                        {
                            cout << "Enter Rating Value:\n";
                            int rate;
                            cin >> rate;
                            book.rateBook(rate);
                            break;
                        }
                        else if (book3choose == 6)
                        {
                            break;
                        }
                    }}
                    else if (book2choose == 2)
                    {

                        cout << "Enter Id\n";
                        int id;
                        cin >> id;
                        Book book = BL.searchBook(id);
                        cout << book;

                    }
                    else if (book2choose == 3)
                    {
                        break;
                    }
                }

            else if(In_2==3){
                    cout << BL;
                }

            else if (In_2==4){
                  cout<<BL.getTheHighestRatedBook();
                  break;
               }

            else if (In_2==5){
                User u6;
                int UsId;
                cout << "Enter User ID";
                cin >> UsId;
                u6 = userlist.searchUser(UsId);
                cout << BL.getBooksForUser(u6);
               }

            else if (In_2 == 6){
                cout << "Copied current list (" << BL.getBooksCount() << ") to a new List and switched ti it " << endl;
                BookList Cpbooklist (BL);
                break;
               }

            else {break;}
         }
  }


       //if User Menu is chosen Users menu
     else if (In_1==2){
          //Size of how many timesUser menu will appear
          int s;
          cout << "How many users will be added?" << endl;
          cin>> s;
          UserList userlist(s);

          //Loops of appearing the user menu
          while (true){
                int In_2;
                cout << "USERS MENU" << endl << "1- Create a USER and add it to the list" << endl
                << "2- Search for a user" << endl << "3- Display all users" << endl
                << "4- Back to the main menu" << endl;
                cin >> In_2;

                //when Create a USER is chosen
                if(In_2 == 1){
                     User u1;
                     cout<<"Enter the user information in this order "<<endl
                     <<"Name Age Email Password (space separated)"<<endl;
                     cin >> u1;
                     userlist.addUser(u1);
                     }

                 //when Searching is chosen is chosen
                else if(In_2== 2) {
                   //  User u2;
                     int DeleID;
                     int In_3;
                     while(true){
                        cout << "SEARCH FOR A USER"<< endl << "1-Search by name" <<
                        endl << "2-Search by id" <<endl << "3-Return to Users Menu"<<endl;
                        cin >> In_3;

                        if(In_3==1){
                            cout<< "Enter Name"<<endl;
                            string name;
                            cin >> name;
                            cout<< userlist.searchUser(name);
                            DeleID = userlist.searchUser(name).getId();
                            int In_4;
                            cout << "1- Delete user" <<endl << "2- Return to Users Menu" <<endl;
                            cin >> In_4;

                            while(true){
                             if(In_4==1){
                                userlist.deleteUser(DeleID);
                                break;
                             }
                             else if (In_4==2) {
                                break;
                             }
                            }
                        }

                        else if(In_3==2){
                          cout << "Enter Id"<< endl;
                          int inID;
                          cin >> inID;
                          cout << userlist.searchUser(inID);

                          int In_4;
                          cout << "1- Delete user" <<endl << "2- Return to Users Menu" <<endl;
                          cin >> In_4;

                          while(true){
                            if(In_4==1){
                                userlist.deleteUser(inID);
                                break;
                            }
                            else if (In_4==2) {
                               break;
                            }
                          }
                        }




                        else{
                          break;
                        }
                        }

                }

                //when 3 is chosen
                else if(In_2== 3) {

                    cout << userlist;
                }

                else{

                  break;
                }

       }
       }

       else {
          break;
       }

    }
    return 0;
}


