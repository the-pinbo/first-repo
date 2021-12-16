#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

Node *search(Node *ptr, int key)
{
  while (ptr)
  {
    if (ptr->data == key)
      return ptr;
    ptr = ptr->next;
  }
  return nullptr;
}

Node *search_rec(Node *ptr, int key)
{
  if (ptr == nullptr || ptr->data == key)
    return ptr;
  return search(ptr->next, key);
}

Node *search_move_head(Node *head, int key)
{
  Node *ptr1, *ptr2;
  if (head)
  {
    ptr1 = head->next;
    ptr2 = head;
    if (head->data == key)
      return head;
    while (ptr1)
    {
      if (ptr1->data == key)
      {
        ptr2->next = ptr1->next;
        ptr1->next = head;
        return head;
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }
  return head;
}