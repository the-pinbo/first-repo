#include <iostream>
#include <queue>
using namespace std;

int main()
{
  priority_queue<int> pq;
  pq.push(10);
  pq.push(15);
  pq.push(25);
  pq.push(18);
  pq.push(184);
  pq.push(51);
  pq.push(50);
  cout << pq.size() << endl;
  cout << pq.top() << endl;
  while (!pq.empty())
  {
    cout << pq.top() << endl;
    pq.pop();
  }

  return 0;
}