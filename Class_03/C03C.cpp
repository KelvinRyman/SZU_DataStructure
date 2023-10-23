// DS队列+堆栈–数制转换
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

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
    double decimal = num - integer;

    if (integer == 0) {
      s.push(0);
    } else {
      while (integer > 0) {
        s.push(integer % base);
        integer /= base;
      }
    }
    while (decimal > 0) {
      decimal *= base;
      q.push((int) decimal);
      decimal -= (int) decimal;
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