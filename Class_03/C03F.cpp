// DS栈+队列----排队游戏
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string childQue;
  cin >> childQue;

  char boyChar, girlChar;
  for (char ch : childQue) {
    if (boyChar == 0) {
      boyChar = ch;
    } else if (ch != boyChar) {
      girlChar = ch;
      break;
    }
  }

  stack<int> indices;
  vector<pair<int, int>> pairs;
  for (int i = 0; i < childQue.size(); i++) {
    if (childQue[i] == boyChar) {
      indices.push(i);
    } else if (childQue[i] == girlChar) {
      int boyIndex = indices.top();
      indices.pop();
      pairs.emplace_back(boyIndex, i);
    }
  }

  for (auto &pair : pairs) {
    cout << pair.first << " " << pair.second << endl;
  }
  return 0;
}
