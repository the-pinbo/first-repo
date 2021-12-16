// A complete C++ program to demonstrate the
// working of Circular Linked Lists

#include <bits/stdc++.h>
using namespace std;

// Circular Linked List Node
struct Node
{
  int data;
  struct Node *next;
};

// Function to add a node at the end of a
// Circular Linked List
struct Node *addEnd(struct Node *last, int data)
{
  if (last == NULL)
  {
    // Creating a node dynamically.
    struct Node *temp = new Node;

    // Assigning the data.
    temp->data = data;
    last = temp;

    // Creating the link.
    last->next = last;

    return last;
  }

  struct Node *temp = new Node;

  temp->data = data;
  temp->next = last->next;
  last->next = temp;
  last = temp;

  return last;
}

// Function to traverse a Circular Linked list
// Using a pointer to the Last Node
void traverse(struct Node *last)
{
  struct Node *p;

  // If list is empty, return.
  if (last == NULL)
  {
    cout << "List is empty." << endl;
    return;
  }

  // Pointing to first Node of the list.
  p = last->next;

  // Traversing the list.
  do
  {
    cout << p->data << " ";
    p = p->next;

  } while (p != last->next);
}

// Driver Program
int main()
{
  struct Node *last = NULL;

  last = addEnd(last, 6);
  last = addEnd(last, 4);
  last = addEnd(last, 2);
  last = addEnd(last, 8);
  last = addEnd(last, 12);
  last = addEnd(last, 10);

  traverse(last);

  return 0;
}
