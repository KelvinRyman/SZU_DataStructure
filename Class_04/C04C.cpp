// DS队列+堆栈–数制转换
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    double num;
    cin >> num;
    int base;
    cin >> base;

    stack<int> s;
    queue<int> q;
    int integer = (int) num;
    double demical = num - integer;

    while (integer > 0) {
      s.push(integer % base);
      integer /= base;
    }
    while (demical > 0) {
      demical *= base;
      q.push((int) demical);
      demical -= (int) demical;
    }

    while (!s.empty()) {
      int top = s.top();
      s.pop();
      if (top >= 10) {
        cout << (char) ('A' + top - 10);
      } else {
        cout << top;
      }
    }

    cout << '.';

    int count = 0;
    while (!q.empty() && count < 3) {
      cout << q.front();
      q.pop();
      count++;
    }
    while (count < 3) {
      cout << '0';
      count++;
    }
  }
  return 0;
}