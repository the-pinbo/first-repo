#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int X)
{
  int low{0}, high{n - 1};
  int mid, index = -1;
  while (high >= low)
  {
    mid = (low + high) / 2;
    if (arr[mid] == X)
    {
      index = mid;
      high = mid - 1;
    }
    else if (arr[mid] > X)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return index;
}
int lastOccurrence(int arr[], int n, int X)
{
  int low{0}, high{n - 1};
  int mid, index = -1;
  while (high >= low)
  {
    mid = (low + high) / 2;
    if (arr[mid] == X)
    {
      index = mid;
      if (arr[mid - 1] != X)
        return index;
      low = mid + 1;
    }
    else if (arr[mid] > X)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return index;
}
vector<int> find(int arr[], int n, int x)
{
  vector<int> vec;
  vec.push_back(firstOccurrence(arr, n, x));
  vec.push_back(lastOccurrence(arr, n, x));
  return vec;
}