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
Node *deleteHead(Node *head)
{
  //Your code here
  if (head == nullptr)
    return head;
  Node *to_delete = head;
  head = head->next;
  delete to_delete;
  return head;
}

Node *deleteTail(Node *head)
{
  //Your Code here
  if (head == nullptr)
    return head;
  Node *curr = head, *prev = nullptr;
  while (curr->next)
  {
    prev = curr;
    curr = curr->next;
  }
  delete curr;
  if (prev)
  {
    prev->next = nullptr;
  }
  else
  {
    head = nullptr;
  }
  return head;
}

Node *deleteAtPosition(Node *head, int pos)
{
  //Your Code here
  if (head == nullptr)
    return nullptr;
  Node *curr{head}, *prev{nullptr};
  while (curr and --pos)
  {
    prev = curr;
    curr = curr->next;
  }
  if (prev == nullptr)
  {
    head = curr->next;
    delete curr;
    return head;
  }
  else
  {
    prev->next = curr->next;
    delete curr;
  }
  return head;
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
    head = deleteTail(head);
    displayList(head);
    cout << endl;
  }
  return 0;
} // } Driver Code Ends