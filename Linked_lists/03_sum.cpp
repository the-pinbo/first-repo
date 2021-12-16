#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

int sum_list(Node *ptr)
{
  int sum = 0;
  while (ptr)
  {
    sum += ptr->data;
    ptr = ptr->next;
  }
}

int sum_list_r(Node *ptr)
{
  if (ptr == nullptr)
  {
    return 0;
  }
  return ptr->data + sum_list_r(ptr->next);
}