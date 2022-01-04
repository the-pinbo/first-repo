#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &vec)
{
  vector<int> span(vec.size(), 1);
  for (int i = vec.size() - 1; i >= 0; --i)
  {
    int x{vec.at(i)};
    int span_x = 1;
    for (int j{i - 1}; j >= 0; --j)
    {
      if (vec.at(j) > x)
        break;
      span_x++;
    }
    span.at(i) = span_x;
  }
  return span;
}

vector<int> stockSpan2(vector<int> &vec)
{
  vector<int> span(vec.size(), 1);
  int i = vec.size() - 1;
  while (i >= 0)
  {
    int x = vec.at(i);
    int span_x = 1;
    stack<int> st;
    for (int j = i - 1; j >= 0; --j)
      st.push(vec.at(j));
    while (!(st.empty()) and st.top() <= x)
    {
      span_x++;
      st.pop();
    }
    span.at(i--) = span_x;
    st.empty();
  }
  return span;
}

vector<int> prevGreater(vector<int> &vec)
{
  vector<int> span(vec.size(), 1);
  stack<int> st;
  st.push(0);
  for (int i = 1; i < vec.size(); ++i)
  {
    while (!st.empty())
    {
      if (vec.at(st.top()) <= vec.at(i))
        st.pop();
    }
    span.at(i) = st.empty() ? i + 1 : i - st.top();
    st.push(i);
  }
  return span;
}
int main()
{
  vector<int> vec{10, 20, 30, 40};
  vector<int> span{prevGreater(vec)};
  for (auto &x : span)
    cout << x << "  ";
  cout << endl;
  return 0;
}