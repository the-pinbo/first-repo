#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
  vector<int> v;
  void push(int x)
  {
    v.push_back(x);
  }
  int peek()
  {
    return v.back();
  }
  int pop()
  {
    int last = v.back();
    v.pop_back();
    return last;
  }
  int size()
  {
    return v.size();
  }
  bool isEmpty()
  {
    return v.empty();
  }
};
