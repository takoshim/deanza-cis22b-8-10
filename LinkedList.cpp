// Implementation file for the LinkedList class
// Written By: A. Student
// Changed By: Takeo Shimazu
// IDE: Visual Studio Code

#include <iostream>
#include "LinkedList.h"

using namespace std;

/*********************************************
 Constructor
 This function allocates and initializes a sentinel node
      A sentinel (or dummy) node is an extra node added before the first data record.
      This convention simplifies and accelerates some list-manipulation algorithms,
      by making sure that all links can be safely dereferenced and that every list
      (even one that contains no data elements) always has a "first" node.
**********************************************/ 
LinkedList::LinkedList()
{
    head = new Node; // head points to the sentinel node
    head->next = NULL;
    length = 0;
}

int LinkedList::getLength() const {return length;}

/**********************************************
 The insertNode function inserts a new node in a
 sorted linked list
*/
void LinkedList::insertNode(Sales dataIn)
{
 /* Write your code here */
}

/**********************************************
 The deleteNode function searches for a node
 in a sorted linked list; if found, the node is
 deleted from the list and from memory.
**********************************************/
bool LinkedList::deleteNode(string target)
{
  /* Write your code here */
}

/**********************************************
 displayList shows the value
 stored in each node of the linked list
 pointed to by head, except the sentinel node
**********************************************/
void LinkedList::displayList() const
{
 /* Write your code here */
}

/**********************************************
  
  
  
**********************************************/
void LinkedList::displayList(int year) const
{
    /* Write your code here */
}


/**********************************************
  
  
  
**********************************************/
double LinkedList::average() const
{
    /* Write your code here */
}

/**********************************************
 The searchList function looks for a target item
 in the sorted linked list: if found, returns true
 and copies the data in that node to the output parameter
**********************************************/
bool LinkedList::searchList( /* Write your code here */) const
{
   bool found = false;
   /* Write your code here */
   
    return found;
}

/**********************************************
 Destructor
 This function deletes every node in the list.
**********************************************/
LinkedList::~LinkedList()
{
    Node *pCur;     // To traverse the list
    Node *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->next;
    // While pCur is not at the end of the list...
    while(pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}



