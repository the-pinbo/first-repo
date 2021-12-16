#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data) : data{data}, next{nullptr}
  {
  }
};

class MyQueue
{
public:
  size_t size;
  Node *front, *rear;
  MyQueue() : size{0}, front{nullptr}, rear{nullptr}
  {
  }
  void enqueue(int x)
  {
    if (size == 0)
    {
      front = new Node(x);
      rear = front;
    }
    else
    {
      rear->next = new Node(x);
      rear = rear->next;
    }
    size++;
    return;
  }
  void dequeue()
  {
    if (isEmpty())
      ;
    else if (this->size == 1)
    {
      delete front;
      front = rear = nullptr;
    }
    else
    {

      Node *temp = front;
      front = front->next;
      delete temp;
    }
    size--;
    return;
  }
  int get_front()
  {
    return front->data;
  }
  int get_rear()
  {
    return rear->data;
  }

  bool isEmpty()
  {
    return bool(this->size);
  }
};
