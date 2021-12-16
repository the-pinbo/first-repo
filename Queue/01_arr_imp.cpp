#include <bits/stdc++.h>
#define SIZE 100
using namespace std;

class MyQueue
{
public:
  size_t size;
  int *front;
  int *arr;
  MyQueue()
  {
    size = 0;
    arr = new int[SIZE];
    front = (int *)arr;
  }
  ~MyQueue()
  {
    delete[] arr;
  }
  void enqueue(int x)
  {
    int rear = get_rear();
    arr[++rear] = x;
    size++;
  }
  void dequeue()
  {
    if (isEmpty())
      return;
    front++;
    size--;
  }
  int get_front()
  {
    return *front;
  }
  int get_rear()
  {
    int rear = (abs(front - arr) + size - 1) % SIZE;
    return rear;
  }
  bool isFull()
  {
    return size == SIZE;
  }
  bool isEmpty()
  {
    return bool(this->size);
  }
  size_t size()
  {
    return size;
  }
};
