// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to find the kth smallest element in the array.
  int kthSmallest(int arr[], int n, int k)
  {
    // Your code here
    priority_queue<int, vector<int>, greater<int>> pq{arr, arr + n};
    while (--k)
      pq.pop();
    return pq.top();
  }
};
class Solution2
{
public:
  //Function to find the kth smallest element in the array.
  int kthSmallest(int arr[], int n, int k)
  {
    //using a priority queue.
    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < n; i++)
    {
      //if size of priority queue equals k, then we compare the element
      //at top of priority queue with current element in the array.
      if (pq.size() == k)
      {
        //if top element is larger than arr[i], then we pop the top
        //element and add arr[i] to the priority queue.
        if (pq.top() > arr[i])
        {
          pq.pop();
          pq.push(arr[i]);
        }
      }
      //else we just add the current element to the priority queue.
      else if (pq.size() < k)
      {
        pq.push(arr[i]);
      }
    }
    //returning the top element of the priority queue.
    return pq.top();
  }
};
