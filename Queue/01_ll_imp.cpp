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
    if (this->size == 0)
    {
      return;
    };
    if (this->size == 1)
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
    this->size--;
    return;
  }
  int get_front()
  {
    return this->size ? front->data : 0;
  }
  int get_rear()
  {
    return this->size ? rear->data : 0;
  }

  bool isEmpty()
  {
    return (this->size == 0);
  }
};

int main()
{
  MyQueue q;
  cout << "The size of the queue is: " << q.size << endl;
  q.enqueue(10);
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.enqueue(20);
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.enqueue(30);
  q.dequeue();
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.dequeue();
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.dequeue();
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.dequeue();
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.enqueue(100);
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  q.dequeue();
  cout << "The size of the queue is: " << q.size << endl;
  cout << "The front of the queue is: " << q.get_front() << endl;
  cout << "The rear of the queue is: " << q.get_rear() << endl;
  return 0;
}