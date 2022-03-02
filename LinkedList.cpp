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

/**********************************************
 The insertNode function inserts a new node in a
 sorted linked list
**********************************************/
void LinkedList::insertNode(Sales dataIn)
{
    Node *pNew = new Node;
    pNew->data = dataIn;
    Node *pPre = head;
    Node *pCur = head->next;

    while (pCur != NULL && pCur->data < dataIn)
    {
        pCur = pCur->next;
        pPre = pPre->next;
    }
    pPre->next = pNew;
    pNew->next = pCur;

    length++;
}

/**********************************************
 The deleteNode function searches for a node
 in a sorted linked list; if found, the node is
 deleted from the list and from memory.
**********************************************/
bool LinkedList::deleteNode(string target)
{
    Node *pCur = head->next;       // To traverse the list
    Node *pPre = head;        // To point to the previous node
    bool deleted = false;

    while (pCur != NULL && pCur->data != target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur != NULL && pCur->data == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;
}

/**********************************************
 displayList shows the value
 stored in each node of the linked list
 pointed to by head, except the sentinel node
**********************************************/
void LinkedList::displayList() const
{
    Node *pCur = head->next;
    while (pCur) {
        cout << pCur->data << endl;
        pCur = pCur->next;
    }
}

/**********************************************
The purpose of this function is to display the salespeople 
hired in the given year. 
If no one has been hired in the given year display "N/A":  
**********************************************/
void LinkedList::displayList(int year) const
{
    Node *pCur = head->next;
    int counter {0};

    cout << "==== ==================== =============" << endl;
    cout << "Year Name                 Amount Earned" << endl;
    cout << "==== ==================== =============" << endl;
    
    while (pCur) {
        if (pCur->data.getYear() == year) {
            cout << pCur->data;
            counter++;
        }
    }
    if (!counter)
        cout << "N/A" << endl;
    
    cout << "==== ==================== =============" << endl;
}


/**********************************************
  The purpose of this function is to calculate 
  and return the amount sold average.  
**********************************************/
double LinkedList::average() const
{
    int sum {0};
    Node *pCur = head->next;

    while (pCur)
    {
        sum += pCur->data.getAmountSold();
        pCur = pCur->next;
    }
    
    return static_cast<double>(sum) / length;
}

/**********************************************
 The searchList function looks for a target item
 in the sorted linked list: if found, returns true
 and copies the data in that node to the output parameter
**********************************************/
bool LinkedList::searchList(Sales &obj, string target) const
{
    Node *pCur = head->next;
    bool found {false};

    while (pCur && !found)
    {
        if (pCur->data.getName() == target)
        {
            found = true;
            obj = pCur->data; 
        }
        else
            pCur = pCur->next;
    }
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



