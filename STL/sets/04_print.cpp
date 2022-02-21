// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  //Complete this function
  vector<int> uniqueSorted(int arr[], int n)
  {
    set<int, greater<int>> s{arr, arr + n};
    vector<int> vec;
    for (auto &x : s)
      vec.push_back(x);
    return vec;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> ans = ob.uniqueSorted(arr, n);
    for (auto i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends