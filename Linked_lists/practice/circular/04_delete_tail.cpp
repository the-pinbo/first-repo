// { Driver Code Starts
//Initial Template for C++

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

//Back-end complete function Template for C++

int getLength(Node *head)
{
  Node *temp = head;

  int count = 0;
  while (temp->next != head)
  {
    count++;
    temp = temp->next;
  }
  return count + 1;
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
Node *deleteTail(Node *head)
{
  //Your code here
  if (head == nullptr)
    return head;
  if (head->next == head)
  {
    delete head;
    return nullptr;
  }
  Node *ptr{head};
  while (ptr->next->next != head)
    ptr = ptr->next;
  Node *temp{ptr->next};
  ptr->next = temp->next;
  delete temp;
  return head;
}
Node *deleteHead(Node *head)
{
  if (head == nullptr)
    return head;
  if (head->next == head)
  {
    delete head;
    return nullptr;
  }
  Node *ptr{head};
  while (ptr->next != head)
    ptr = ptr->next;
  Node *temp{ptr->next};
  ptr->next = temp->next;
  temp->next = nullptr;
  return ptr->next;
}
Node *deleteAtPosition(Node *head, int pos)
{
  if (head == nullptr)
    return head;
  if (head->next == head)
  {
    delete head;
    return nullptr;
  }
  Node *ptr{head};
  if (pos == 1)
  {
    while (ptr->next != head)
      ptr = ptr->next;
  }
  else
    while (--pos > 1 and ptr->next != head)
    {
      ptr = ptr->next;
    }
  if (ptr->next == head and pos != 1)
    return head;
  Node *temp{ptr->next};
  ptr->next = ptr->next->next;
  return temp == head ? (delete temp), ptr->next : head;
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

    makeCircular(head);

    head = deleteTail(head);

    displayList(head);

    cout << endl;
  }
  return 0;
} // } Driver Code Ends