// DS 串应用 – 串替换
#include <bits/stdc++.h>

using namespace std;

class StrSolution {
 public:
  explicit StrSolution(string mainStr) : mainStr(std::move(mainStr)) {}

  string kmpReplace(const string &pattern, const string &replaceStr) {
    string replacedStr;
    int position = kmpSearch(pattern, 0);
    if (position != -1) {
      replacedStr = mainStr.substr(0, position) + replaceStr + mainStr.substr(position + pattern.size());
    } else {
      replacedStr = mainStr;
    }
    return replacedStr;
  }

  int kmpSearch(const string &pattern, int pos) {
    int n = static_cast<int>(mainStr.size());
    int m = static_cast<int>(pattern.size());
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
        return i - j;
      }
    }
    return -1;
  }

 private:
  string mainStr;
  vector<int> next;

  void getNextArr(const string &pattern) {
    int m = static_cast<int>(pattern.size());
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
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string mainStr, patternStr, replaceStr;
    cin >> mainStr >> patternStr >> replaceStr;

    StrSolution strSolution(mainStr);
    string replacedStr = strSolution.kmpReplace(patternStr, replaceStr);

    cout << mainStr << endl;
    cout << replacedStr << endl;
  }

  return 0;
}