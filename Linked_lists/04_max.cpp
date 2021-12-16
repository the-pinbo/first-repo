#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

int max_no(Node *ptr)
{
  int max = INT32_MIN;
  while (ptr)
  {
    if (ptr->data > max)
      max = ptr->data;
    ptr = ptr->next;
  }
  return max;
}

int max_no_r(Node *ptr)
{
  if (ptr == nullptr)
    return INT32_MIN;
  int next_max = max_no_r(ptr->next);
  if (ptr->data > next_max)
    return ptr->data;
  return next_max;
  // // or
  // return next_max > ptr->data ? next_max : ptr->data;
}