#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

void display(Node *ptr)
{
  while (ptr)
  {
    cout << ptr->data << endl;
    ptr = ptr->next;
  }
}

void diplay_r(Node *ptr)
{
  if (ptr == nullptr)
  {
    return;
  }
  cout << ptr->data << endl;
  diplay_r(ptr->next);
  return;
}

void diplay_r_rev(Node *ptr)
{
  if (ptr == nullptr)
  {
    return;
  }
  diplay_r(ptr->next);
  cout << ptr->data << endl;
  return;
}