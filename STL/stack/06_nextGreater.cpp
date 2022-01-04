#include <bits/stdc++.h>
using namespace std;

vector<int> prevGreater(vector<int> &vec)
{
  vector<int> prevGre_vec(vec.size(), -1);
  stack<int> st;
  st.push(vec.at(0));
  for (int i = 1; i < vec.size(); ++i)
  {
    while (!st.empty())
    {
      if (st.top() <= vec.at(i))
        st.pop();
      else
        break;
    }
    prevGre_vec.at(i) = st.empty() ? -1 : st.top();
    st.push(vec.at(i));
  }
  return prevGre_vec;
}

vector<int> nextGreater(vector<int> &vec)
{
  reverse(vec.begin(), vec.end());
  vector<int> prevGre_vec{prevGreater(vec)};
  reverse(prevGre_vec.begin(), prevGre_vec.end());
  return prevGre_vec;
}
vector<int> nextGreater2(vector<int> &vec)
{
  vector<int> nextGre_vec(vec.size(), -1);
  stack<int> st;
  st.push(vec.at(vec.size() - 1));
  for (int i = vec.size() - 1; i >= 0; --i)
  {
    while (!st.empty())
    {
      if (st.top() <= vec.at(i))
        st.pop();
      else
        break;
    }
    nextGre_vec.at(i) = st.empty() ? -1 : st.top();
    st.push(vec.at(i));
  }
  return nextGre_vec;
}
int main()
{
  vector<int> vec{15, 10, 18, 12, 4, 6, 2, 8};
  vector<int> nextGre_vec{nextGreater(vec)};
  for (auto &x : nextGre_vec)
    cout << x << "  ";
  cout << endl;
  return 0;
}