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

int sumOfElements(struct Node *head)
{
  int sum{0};
  while (head)
  {
    sum += head->data;
    head = head->next;
  }
  return sum;
}
