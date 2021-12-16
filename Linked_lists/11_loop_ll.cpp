#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
};

Node *loop(Node *head)
{
  Node *fast = head, *slow = head;
  while (true)
  {
    if (slow == nullptr or (fast == nullptr or fast->next == nullptr))
      return nullptr;
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  return slow;
}