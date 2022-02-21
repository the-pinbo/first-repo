// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to return kth largest element from an array.
  int KthLargest(int arr[], int n, int k)
  {
    // Your code here
    priority_queue<int> pq{arr, arr + n};
    while (--k)
    {
      pq.pop();
    }
    return pq.top();
  }
};
class Solution2
{
public:
  //Function to return kth largest element from an array.
  int KthLargest(int arr[], int n, int k)
  {
    //implementing MinHeap using priority queue.
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
      //if size of priority queue becomes equal to k and top
      //element is smaller than arr[i], we pop the front
      //element and push arr[i] in priority queue.
      if (pq.size() == k && pq.top() < arr[i])
      {
        pq.pop();
        pq.push(arr[i]);
      }
      //else we just push arr[i] in priority queue.
      else if (pq.size() < k)
        pq.push(arr[i]);
    }
    //returning the top element of priority queue.
    return pq.top();
  }
};
