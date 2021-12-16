#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
};

Node *reverse(Node *head)
{
  if (head == nullptr or head->next == nullptr)
    return head;
  Node *prev = nullptr, *curr = head;

  while (head != nullptr)
  {
    head = head->next;
    curr->next = prev;
    prev = curr;
    curr = head;
  }
  return curr;
}
void reverse_r(Node *prev, Node *curr)
{
  if (curr == nullptr)
    return;
  reverse_r(curr, curr->next);
  curr->next = prev;
  return;
}