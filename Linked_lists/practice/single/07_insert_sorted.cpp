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

Node *insertInSorted(Node *head, int data)
{
  //Your code here
  Node *curr{head}, *prev{nullptr}, *temp = new Node(data);
  while (curr and curr->data < data)
  {
    prev = curr;
    curr = curr->next;
  }
  if (prev == nullptr)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    temp->next = prev->next;
    prev->next = temp;
  }
  return head;
}

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
    cin >> data;
    head = insertInSorted(head, data);
    displayList(head);
    cout << endl;
  }
  return 0;
} // } Driver Code Ends