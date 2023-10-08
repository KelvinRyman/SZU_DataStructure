// DS 串应用 - KMP 算法
#include <bits/stdc++.h>
using namespace std;

class StrSolution {
 public:
  StrSolution(const string &mainStr) : mainStr(mainStr) {}

  int kmpSearch(const string &pattern, int pos) {
    int n = mainStr.size();
    int m = pattern.size();
    int i = pos, j = 0;
    getNextArr(pattern);

    while (i < n) {
      if (j == -1 || mainStr[i] == pattern[j]) {
        i++;
        j++;
      } else {
        j = next[j];
      }

      if (j == m) {
        return i - j + 1;
      }
    }
    return 0;
  }

  void printNext() {
    for (int i = 0; i < next.size(); i++) {
      cout << next[i];
      if (i < next.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

 private:
  string mainStr;
  vector<int> next;

  void getNextArr(const string &pattern) {
    int m = pattern.size();
    next.resize(m);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
      if (j == -1 || pattern[i] == pattern[j]) {
        i++;
        j++;
        next[i] = j;
      } else {
        j = next[j];
      }
    }
    printNext();
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string mainStr, patternStr;
    cin >> mainStr >> patternStr;
    StrSolution ss(mainStr);

    int position = ss.kmpSearch(patternStr, 0);
    cout << position << endl;
  }

  return 0;
}
