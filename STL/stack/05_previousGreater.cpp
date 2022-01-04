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
int main()
{
  vector<int> vec{15, 10, 18, 12, 4, 6, 2, 8};
  vector<int> prevGre_vec{prevGreater(vec)};
  for (auto &x : prevGre_vec)
    cout << x << "  ";
  cout << endl;
  return 0;
}