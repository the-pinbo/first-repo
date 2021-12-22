#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
  int size;
  int *arr;
  int cpacity;

public:
  Heap(int size) : size{size}, cpacity{0}
  {
    arr = new int[size];
    memset(arr, 0, size * sizeof(int));
  }
  int left(int i)
  {
    return 2 * i + 1;
  }
  int right(int i)
  {
    return 2 * i + 2;
  }
  int parent(int i)
  {
    return (i - 1) / 2;
  }
  void insert(int key);
  void heapify(int root);
  void heapify();
  int extractMin();
  void decreaseKey(int i, int value);
  void deleteIndex(int i);
  void buildHeap();
};

void Heap::insert(int x)
{
  int i{0};
  while (i < this->cpacity)
    ++i;
  this->arr[i] = x;
  while (i > 0)
  {
    if (arr[parent(i)] > arr[i])
      swap(arr[parent(i)], arr[i]);
    i = parent(i);
  }
}

void Heap::heapify(int root)
{
  int rt{right(root)}, lf{left(root)};
  if (arr[root] < min(arr[left(root)], arr[right(root)]))
  {
    if (arr[left(root)] < arr[root])
    {
      swap(arr[root], arr[left(root)]);
      heapify(left(root));
    }
    else
    {
      swap(arr[root], arr[right(root)]);
      heapify(right(root));
    }
  }
  return;
}

void Heap::heapify()
{
  int i{0};
  int rt{right(i)}, lf{left(i)}, small{i};
  while (rt < this->cpacity and lf < this->cpacity)
  {
    if (arr[lf] < arr[small])
      small = lf;
    if (arr[rt] < arr[small])
      small = rt;
    if (small == i)
      return;
    swap(arr[small], arr[i]);
    i = small;
    rt = right(i), lf = left(i);
  }
}

int Heap::extractMin()
{
  if (this->cpacity == 0)
    return INT32_MIN;
  if (this->cpacity == 1)
    return arr[--this->cpacity];
  swap(arr[0], arr[--this->cpacity]);
  heapify(0);
  return arr[this->cpacity];
}
void Heap::decreaseKey(int i, int value)
{
  this->arr[i] = value;
  while (i > 0 and this->arr[i] < this->arr[parent(i)])
  {
    swap(this->arr[i], this->arr[parent(i)]);
    i = parent(i);
  }
}
void Heap::deleteIndex(int i)
{
  swap(arr[i], arr[--this->cpacity]);
  heapify(i);
  //   // or
  //   decreaseKey(i, INT32_MIN);
  //   extractMin();
}
void Heap::buildHeap()
{
  int i = this->cpacity & 1 ? this->cpacity - 2 : this->cpacity - 1;
  while (i >= 0)
  {
    heapify(parent(i));
    i -= 2;
  }
  // // or
  // int i = (this->cpacity - 2) / 2;
  // while (i >= 0)
  //   heapify(parent(i--));
}