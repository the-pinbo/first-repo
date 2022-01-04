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

Node *newNode(int data)
{
  Node *temp = new Node(data);

  return temp;
}

void displayList(Node *head)
{
  Node *temp = head;
  while (temp->next != head)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << temp->data << " ";
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
void insertAtPosition(Node *head, int pos, int data)
{
  //Your code here
  Node *ptr{head};
  while (--pos and ptr->next != head)
  {
    ptr = ptr->next;
  }
  if (pos != 0)
    return;
  Node *temp = new Node(data);
  temp->next = ptr->next;
  ptr->next = temp;
}

// { Driver Code Starts.

void makeCircular(Node *head)
{
  Node *temp = head;

  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = head;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    int x;
    cin >> x;
    head = new Node(x);
    tail = head;
    for (int i = 0; i < n - 1; i++)
    {
      cin >> x;
      tail->next = new Node(x);
      tail = tail->next;
    }

    int pos;
    cin >> pos;

    int data;
    cin >> data;

    makeCircular(head);

    insertAtPosition(head, pos, data);

    displayList(head);

    cout << endl;
  }
  return 0;
} // } Driver Code Ends