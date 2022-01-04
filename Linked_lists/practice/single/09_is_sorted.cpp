// { Driver Code Starts
//Initial Template for C++

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

void displayList(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

// } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/

bool isSortedInc(Node *head)
{
  if (head == nullptr or head->next == nullptr)
    return true;
  Node *curr{head->next}, *pre{head};
  while (curr)
  {
    if (curr->data < pre->data)
      return false;
    pre = curr;
    curr = curr->next;
  }
  return true;
}
bool isSortedDec(Node *head)
{
  if (head == nullptr or head->next == nullptr)
    return true;
  Node *curr{head->next}, *pre{head};
  while (curr)
  {
    if (curr->data > pre->data)
      return false;
    pre = curr;
    curr = curr->next;
  }
  return true;
}
bool isSorted(Node *head)
{
  return isSortedInc(head) or isSortedDec(head);
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
      cin >> data;
      tail->next = new Node(data);
      tail = tail->next;
    }
    cout << isSorted(head) << endl;
  }
  return 0;
} // } Driver Code Ends