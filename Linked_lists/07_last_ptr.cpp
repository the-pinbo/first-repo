#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
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
    (*tail_ref) = new_node;
    return;
  }
  /* 5. Change the next of last node */
  (*tail_ref)->next = new_node;
  /* 6. Change the next of last node */
  (*tail_ref) = new_node;
  return;
}