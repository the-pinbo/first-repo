// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Complete this function
string Sorted_Characters(const string &str)
{
  // Your Code Here
  set<char> s{str.begin(), str.end()};
  string st;
  for (auto &x : s)
    st += x;
  return st;
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    string str;
    cin >> str;

    string result;
    result = Sorted_Characters(str);
    cout << result;

    cout << endl;
  }
  return 0;
} // } Driver Code Ends