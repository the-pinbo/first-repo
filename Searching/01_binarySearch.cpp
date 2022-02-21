// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to search x in arr
  // arr: input array
  // X: element to be searched for
  int search(int arr[], int N, int X)
  {
    int low{0}, high{N - 1};
    int mid;
    while (high >= low)
    {
      mid = (low + high) / 2;
      if (arr[mid] == X)
        return mid;
      if (arr[mid] > X)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};
