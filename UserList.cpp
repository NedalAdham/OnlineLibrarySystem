#include "UserList.h"
#include "User.h"
#include<iostream>
#include <stdlib.h>
using namespace std;
//Private Member Variables
     /*   User* users;
        int capacity;
        int usersCount;*/


//Default Constructor, It takes the Capacity of the list...
    UserList::UserList(int capacity){
        this->capacity = capacity;
        users = new User[capacity];
        usersCount=0;
    };

//Adding User To the list
    void UserList:: addUser(User user){

        users[usersCount]= user;
            usersCount++;
    }; // at the end of the array.


//Search by Name
    User& UserList::searchUser(string name){
        int index;
        for(int i=0; i<usersCount; i++)
           {
            if(name == users[i].getName()){
                index = i;
                //If it's found, break loop and return it...
                break;
            }
    }
     return users[index];
};

//Search by Id
    User&UserList:: searchUser(int id){
        //Return The position
        return users[id-1];

    };

    //Delete User and shifting others...
    void UserList::deleteUser(int id){
       //Form that Id-1 where the position of user, Shift.
        for (int i = id-1 ; i<usersCount; i++)
        {
            users[i] = users[i+1];
        }
        usersCount = usersCount-1;

    };


    ostream &operator<<( ostream &output, UserList &userList ){
        for (int i=0; i<userList.usersCount; i++){
                output << userList.users[i];}
        return output;
        };//to display all books


    UserList::~UserList(){
        delete [] users;
    };
