// DS队列–组队列
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, x;
  cin >> t;
  unordered_map<int, int> group;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> x;
      group[x] = i;
    }
  }
  queue<int> q;
  queue<int> q_group[10];
  string command;
  while (cin >> command) {
    if (command == "STOP") {
      break;
    } else if (command == "ENQUEUE") {
      cin >> x;
      if (q_group[group[x]].empty()) {
        q.push(group[x]);
      }
      q_group[group[x]].push(x);
    } else if (command == "DEQUEUE") {
      int front_group = q.front();
      cout << q_group[front_group].front() << " ";
      q_group[front_group].pop();
      if (q_group[front_group].empty()) {
        q.pop();
      }
    }
  }
  return 0;
}