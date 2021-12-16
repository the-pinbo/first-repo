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
  Node *head;
  MyQueue()
  {
    size = 0;
    head = nullptr;
  }
  void push(int x)
  {
    if (size == 0)
    {
      head = new Node(x);
      size++;
      return;
    }
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    size++;
    return;
  }
  int peek()
  {
    return this->size ? head->data : 0;
  }
  int pop()
  {
    if (size == 0)
    {
      return 0;
    }
    int last = this->peek();
    Node *temp = this->head;
    this->head = this->head->next;
    delete temp;
    size--;
    return last;
  }

  bool isEmpty()
  {
    return bool(this->size);
  }
};

// Driver Code
int main()
{
  MyQueue st;
  cout << "The size of the stack is: " << st.size << endl;
  st.push(10);
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  st.push(20);
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  st.push(30);
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  cout << "Element popped is: " << st.pop() << endl;
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  cout << "Element popped is: " << st.pop() << endl;
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  cout << "Element popped is: " << st.pop() << endl;
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  cout << "Element popped is: " << st.pop() << endl;
  cout << "The size of the stack is: " << st.size << endl;
  cout << "The top of the stack is: " << st.peek() << endl;
  return 0;
}