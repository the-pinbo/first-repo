#include <bits/stdc++.h>
using namespace std;

int main()
{
  queue<int> q;
  q.emplace(10);
  q.emplace(20);
  q.emplace(30);
  q.emplace(40);
  q.emplace(50);
  int k = 3;
  stack<int> st;
  for (int i = 0; i < k; ++i)
  {
    int x = q.front();
    st.push(x);
    q.pop();
  }
  while (!st.empty())
  {
    int x = st.top();
    q.emplace(x);
    st.pop();
  }
  for (int i = q.size() - k; i >= 0; --i)
  {
    int x = q.front();
    q.pop();
    q.emplace(x);
  }
  while (!q.empty())
  {
    cout << q.front() << endl;
    q.pop();
  }
  return 0;
}