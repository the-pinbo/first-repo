#include <bits/stdc++.h>
using namespace std;
// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

/* Given a reference (pointer to pointer) to the 
   head of a list and an int, insert a new node 
   on the front of the list. */

void push(struct Node **head_ref, int new_data)
{
  /* 1. allocate node */
  Node *new_node = new Node;

  /* 2. put in the data  */
  new_node->data = new_data;

  /* 3. Make next of new node as head */
  new_node->next = (*head_ref);

  /* 4. move the head to point to the new node */
  (*head_ref) = new_node;
}
/* Given a reference (pointer to pointer) to  
   the head of a list and an int, appends a new 
   node at the end  */

void append(struct Node **head_ref, int new_data)
{
  /* 1. allocate node */
  Node *new_node = new Node;

  struct Node *last = *head_ref; /* used in step 5*/

  /* 2. put in the data  */
  new_node->data = new_data;

  /* 3. This new node is going to be the last node,  
          so make next of it as NULL*/
  new_node->next = NULL;

  /* 4. If the Linked List is empty, then make 
          the new node as head */
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  /* 5. Else traverse till the last node */
  while (last->next != NULL)
    last = last->next;

  /* 6. Change the next of last node */
  last->next = new_node;
  return;
}

/* Given a node prev_node, insert a new node
   after the given prev_node */

void insertAfter(struct Node *prev_node, int new_data)
{
  /* 1. check if the given prev_node is NULL */
  if (prev_node == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }

  /* 2. allocate new node */
  Node *new_node = new Node;

  /* 3. put in the data  */
  new_node->data = new_data;

  /* 4. Make next of new node as next of prev_node */
  new_node->next = prev_node->next;

  /* 5. move the next of prev_node as new_node */
  prev_node->next = new_node;
}

/*Insert at the correct position of a sorted linked list*/
void insert(Node **head_ref, int x)
{
  Node *new_node = new Node;
  new_node->data = x;
  new_node->next = nullptr;
  if (*head_ref == nullptr)
  {
    *head_ref = new_node;
    return;
  }
  Node *p = *head_ref, *q;
  while (p and p->data < x)
  {
    q = p;
    p = p->next;
  }
  if (p == *head_ref)
  {
    new_node->next = (*head_ref);
    *head_ref = new_node;
  }
  else
  {
    new_node->next = p;
    q->next = new_node;
  }
  return;
}