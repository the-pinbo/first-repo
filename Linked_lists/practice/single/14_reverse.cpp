// { Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
  //Function to reverse a linked list.
  struct Node *reverseList(struct Node *head)
  {
    // code here
    // return head of reversed list
    Node *ptr1{head->next}, *ptr2{head}, *ptr3{nullptr};
    while (ptr1)
    {
      ptr2->next = ptr3;
      ptr3 = ptr2;
      ptr2 = ptr1;
      ptr1 = ptr1->next;
    }
    ptr2->next = ptr3;
    return ptr2;
  }
  //Back-end complete function Template for C

  struct Node *reverseList2(struct Node *head)
  {

    if (head == NULL)
      return NULL;

    //taking three pointers to store the current, previous and next nodes.
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = current->next;

    while (current != NULL)
    {
      //taking the next node as next.
      next = current->next;

      //storing the previous node in link part of current node.
      current->next = prev;

      //updating prev from previous node to current node.
      prev = current;

      //updating current node to next node.
      current = next;
    }

    return prev;
  }
};

// { Driver Code Starts.

void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

/* Driver program to test above function*/
int main()
{
  int T, n, l, firstdata;
  cin >> T;

  while (T--)
  {
    struct Node *head = NULL, *tail = NULL;

    cin >> n;

    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;

    for (int i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }

    Solution ob;
    head = ob.reverseList(head);

    printList(head);
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends