#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void binSort(int a[], int n)
  {
    int zero_count = 0;
    for (int i = 0; i < n; ++i)
    {
      if (a[i] == 0)
        zero_count++;
    }
    int i = 0;
    while (i < zero_count)
    {
      a[i++] = 0;
    }
    while (i < n)
    {
      a[i++] = 1;
    }
    return;
  }

  void binSortGFG(int A[], int N)
  {
    int low = 0, high = N - 1;

    //Using segregation method.
    while (low <= high)
    {

      //If element at left index is 0, we increase the left index.
      if (A[low] == 0)
      {
        low++;
      }
      //Else If element at high index is 1, we decrease the right index.
      else if (A[high] == 1)
      {
        high--;
      }
      //Else, we swap the elements at left and right index.
      else
      {
        int temp = A[low];
        A[low] = A[high];
        A[high] = temp;
        //Updating values of left and right index after swapping.
        low++;
        high--;
      }
    }
  }
};