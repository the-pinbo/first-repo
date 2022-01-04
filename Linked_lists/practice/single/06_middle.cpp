// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// function to display the linked list
void display(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *insertInMiddle(Node *head, int x);

int main()
{
  int T, n, x;
  cin >> T;
  while (T--)
  {
    cin >> n >> x;

    struct Node *head = new Node(x);
    struct Node *tail = head;

    for (int i = 0; i < n - 1; i++)
    {
      cin >> x;
      tail->next = new Node(x);
      tail = tail->next;
    }

    cin >> x;
    head = insertInMiddle(head, x);
    display(head);
  }
  return 0;
}
// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to insert a node in the middle of the linked list.
Node *insertInMiddle(Node *head, int x)
{
  Node *slow{head}, *fast{head};
  Node *temp = new Node(x);
  if (head == nullptr)
    return temp;
  while (fast and fast->next and fast->next->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  temp->next = slow->next;
  slow->next = temp;
  return head;
}

//Function to insert a node in the middle of the linked list.
Node *insertInMiddle2(Node *head, int x)
{
  Node *ptr{head};
  Node *temp = new Node(x);
  int n{0};
  if (head == nullptr)
    return temp;
  while (ptr)
  {
    n++;
    ptr = ptr->next;
  }
  ptr = head;
  int mid = n % 2 ? (n / 2) : n / 2 - 1;
  for (int i = 0; i < mid; ++i)
    ptr = ptr->next;
  temp->next = ptr->next;
  ptr->next = temp;
  return head;
}
Node *insertInMiddle3(Node *head, int x)
{
  //if list is empty, we just return the new node.
  if (head == NULL)
    return (new Node(x));
  else
  {
    //creating new node.
    Node *newNode = new Node(x);

    //we take two pointers one of which moves to next node in each
    //iteration and the other moves two nodes in one iteration.
    Node *slow = head;
    Node *fast = head->next;

    //therefore when fast will reach end, slow will be at the middle point.
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    //we store the next node after slow in link part of the new node.
    newNode->next = slow->next;

    //we also store the new node in link part of the slow node.
    slow->next = newNode;
  }
  return head;
}