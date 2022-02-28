// Specification file for the LinkedList class
// Written By: A. Student
// Changed By: Takeo Shimazu
// IDE: Visual Studio Code

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Sales.h"

class LinkedList
{
private:
    struct Node
    {
        Sales data;
        Node *next;
    };

    Node *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Basic Linked list operations
    int getLength() const {return length;}
    void insertNode(Sales);
    bool deleteNode(string);
    void displayList() const;
    void searchList()const;
    
    // Other functions
   void displayList(int) const;
   double average() const;
};

#endif
