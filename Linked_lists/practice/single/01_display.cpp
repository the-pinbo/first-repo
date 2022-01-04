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

vector<int> displayList(Node *head)
{
  vector<int> v;
  while (head)
  {
    v.push_back(head->data);
    head = head->next;
  }
  return v;
}
