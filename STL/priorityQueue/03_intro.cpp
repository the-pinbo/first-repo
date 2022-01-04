#include <iostream>
#include <queue>
using namespace std;

int main()
{
  vector<int> vec{10, 21, 41, 1, 20, 1, -5, 5};
  priority_queue<int> pq(vec.begin(), vec.end());
  cout << pq.size() << endl;
  cout << pq.top() << endl;
  while (!pq.empty())
  {
    cout << pq.top() << endl;
    pq.pop();
  }

  return 0;
}