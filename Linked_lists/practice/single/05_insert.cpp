#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
  //Function to insert a node at the beginning of the linked list.
  Node *insertAtBegining(Node *head, int x)
  {
    Node *ptr = new Node(x);
    ptr->next = head;
    return ptr;
  }

  //Function to insert a node at the end of the linked list.
  Node *insertAtEnd(Node *head, int x)
  {
    Node *ptr = new Node(x);
    if (head == nullptr)
      return ptr;
    Node *curr{head};
    while (curr->next)
    {
      curr = curr->next;
    }
    curr->next = ptr;
    return head;
  }
  void insertAtPosition(Node *head, int pos, int data)
  {
    //Your code here
    Node *temp = new Node(data);
    if (head == nullptr)
    {
      head = temp;
      return;
    }
    Node *curr = head;
    for (int i = 1; curr and i < pos; ++i)
      curr = curr->next;
    if (curr == nullptr)
      return;
    temp->next = curr->next;
    curr->next = temp;
  }
};
