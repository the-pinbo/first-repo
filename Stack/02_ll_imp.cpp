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

class MyStack
{
public:
  vector<int> v;
  size_t size;
  Node *head;
  Node *tail;
  MyStack()
  {
    size = 0;
    head = nullptr;
    tail = nullptr;
  }
  ~MyStack()
  {
    size = 0;
    head = nullptr;
  }
  void push(int x)
  {
    if (size == 0)
    {
      head = new Node(x);
      tail = head;
      size++;
      return;
    }
    tail->next = new Node(x);
    tail = tail->next;
    size++;
    return;
  }
  int peek()
  {
    return tail->data;
  }
  int pop()
  {
    if (size == 0)
    {
      return;
    }
    int last = this->peek();
    if (size == 1)
    {
      size--;
      delete head;
      head = nullptr;
    }
    else
    {
      while (head->next->next)
      {
        head = head->next;
      }
      Node *temp = head->next;
      head->next = nullptr;
      delete temp;
      size--;
    }
    return last;
  }

  bool isEmpty()
  {
    return bool(this->size);
  }
};
