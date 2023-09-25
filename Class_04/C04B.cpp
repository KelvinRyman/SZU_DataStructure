// DS队列----银行简单模拟
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  queue<int> A, B;
  int id;
  for (int i = 0; i < n; ++i) {
    cin >> id;
    if (id % 2 == 0)
      B.push(id);
    else
      A.push(id);

  }
  while (!A.empty() || !B.empty()) {
    if (!A.empty()) {
      cout << A.front() << " ";
      A.pop();
    }
    if (!A.empty()) {
      cout << A.front() << " ";
      A.pop();
    }
    if (!B.empty()) {
      cout << B.front() << " ";
      B.pop();
    }
  }
  cout << '\n';
  return 0;
}