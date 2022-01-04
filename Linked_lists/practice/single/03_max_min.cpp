#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

int maximum(Node *head)
{
  int max{INT32_MIN};
  while (head)
  {
    if (head->data > max)
      max = head->data;
    head = head->next;
  }
  return max;
}

int minimum(Node *head)
{
  int min{INT32_MAX};
  while (head)
  {
    if (head->data < min)
      min = head->data;
    head = head->next;
  }
  return min;
}
