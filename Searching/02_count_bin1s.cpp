// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to count number of Ones
  // arr: input array
  // N: size of input array
  int countOnes2(int arr[], int N)
  {
    int low = 0;
    int high = N - 1;
    int mid;
    if (arr[low] == 0)
      return 0;
    if (arr[low] == 1)
      return N;

    while (arr[high] != 1)
    {
      mid = (high + low) / 2;

      if (arr[mid] == 0)
      {
        high = mid - 1;
        continue;
      }
      high = high - 1;
    }
    return high + 1;
  }
};

int countOnes(int arr[], int N)
{
  // 0 0 1 1 1 1 1
  int low = 0;
  int high = N - 1;
  int mid;

  while (high >= low)
  {
    mid = (high + low) / 2;

    if (arr[mid] == 0)
      low = mid + 1;
    else
    {
      // if it is the first occurrence then return size - index
      if (mid == 0 or arr[mid - 1] != arr[mid])
        return (N - mid);
      high = mid - 1;
    }
  }
  return 0;
}

// 1 1 1 1 1 0 0 0
int countOnes(int arr[], int N)
{
  int low = 0;
  int high = N - 1;
  int mid;

  while (high >= low)
  {
    mid = (high + low) / 2;

    if (arr[mid] == 0)
      high = mid - 1;
    else
    {
      // if it is the first occurrence then return size - index
      if (mid == N - 1 or arr[mid + 1] != arr[mid])
        return (mid + 1);
      low = mid + 1;
    }
  }
  return 0;
}
