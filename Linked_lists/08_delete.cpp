#include <bits/stdc++.h>
using namespace std;
// A linked list node
struct Node
{
  int data;
  struct Node *next;
};
/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */

void deleteNode(struct Node **head_ref, int key)
{
  // Store head node
  struct Node *temp = *head_ref, *prev;

  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next; // Changed head
    free(temp);             // free old head
    return;
  }

  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in linked list
  if (temp == NULL)
    return;

  // Unlink the node from linked list
  prev->next = temp->next;

  free(temp); // Free memory
}

/* Given a reference (pointer to pointer) to the head of a list 
   and a position, delete the node at the given position */
void deleteNode(struct Node **head_ref, int position)
{
  // If linked list is empty
  if (*head_ref == NULL)
    return;

  // Store head node
  struct Node *temp = *head_ref;

  // If head needs to be removed
  if (position == 0)
  {
    *head_ref = temp->next; // Change head
    free(temp);             // free old head
    return;
  }

  // Find previous node of the node to be deleted
  for (int i = 0; temp != NULL && i < position - 1; i++)
    temp = temp->next;

  // If position is more than number of ndoes
  if (temp == NULL || temp->next == NULL)
    return;

  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  struct Node *next = temp->next->next;

  // Unlink the node from linked list
  free(temp->next); // Free memory

  temp->next = next; // Unlink the deleted node from list
}
