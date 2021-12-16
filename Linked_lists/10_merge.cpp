#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
};

Node *merge_ll(Node *first, Node *second)
{
  Node *head = first->data > second->data ? second : first;
  Node *ptr = head;
  while (first != nullptr and second != nullptr)
  {
    if (first->data > second->data)
    {
      ptr->next = second;
      second = second->next;
    }
    else
    {
      ptr->next = first;
      first = first->next;
    }
  }
  if (first != nullptr)
  {
    ptr->next = first;
  }
  else
    ptr->next = second;
  return head;
}