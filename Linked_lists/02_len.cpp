#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};

int len(Node *ptr)
{
  int count = 0;
  while (ptr)
  {
    count++;
    ptr = ptr->next;
  }
  return count;
}
int len_rec(Node *ptr)
{
  if (ptr == nullptr)
    return 0;
  return len_rec(ptr->next) + 1;
}
