// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T, i, n, l, k;

  cin >> T;

  while (T--)
  {

    cin >> n >> k;
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
    if (k == 1 && n >= 1)
      tail->next = head;

    printf("%d\n", isCircular(head));
  }
  return 0;
}

// } Driver Code Ends

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/
Node *insertInHead(Node *head, int data)
{
  Node *curr{head};
  while (curr->next != head)
    curr = curr->next;
  curr->next = new Node(data);
  curr->next->next = head;
  return curr->next;
}
Node *insertInTail(Node *head, int data)
{
  Node *curr{head};
  while (curr->next != head)
    curr = curr->next;
  curr->next = new Node(data);
  curr->next->next = head;
  return head;
}

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
  // Your code here
  if (head == nullptr)
    return true;
  Node *fast{head}, *slow{head};
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

bool isCircular2(struct Node *head)
{
  if (!head)
    return true;

  Node *temp = head;

  while (head && head->next != temp)
    head = head->next;

  if (!head || !(head->next))
    return false;

  return true;
}