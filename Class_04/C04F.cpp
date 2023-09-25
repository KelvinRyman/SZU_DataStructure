// DS栈+队列----排队游戏
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  string childrenQueue;
  cin >> childrenQueue;

  char boyChar, girlChar; // 存储小男孩和小女孩的字符
  char otherChar; // 存储可能的其他字符

  // 找到两个不同的字符
  for (char ch : childrenQueue) {
    if (boyChar == 0) {
      boyChar = ch;
    } else if (ch != boyChar) {
      girlChar = ch;
      break;
    }
  }

  stack<int> boyIndices;
  vector<pair<int, int>> pairs;

  for (int i = 0; i < childrenQueue.size(); i++) {
    if (childrenQueue[i] == boyChar) {
      boyIndices.push(i);
    } else if (childrenQueue[i] == girlChar) {
      int boyIndex = boyIndices.top();
      boyIndices.pop();
      pairs.push_back({boyIndex, i});
    }
  }

  for (const auto& pair : pairs) {
    cout << pair.first << " " << pair.second << endl;
  }

  return 0;
}
