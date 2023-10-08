// 串应用 - 计算一个串的最长的真前后缀
#include <bits/stdc++.h>
using namespace std;

string matched_Prefix_postfix(const string &str) {
  int n = static_cast<int>(str.size());
  string result;

  for (int i = 1; i < n; i++) {
    string prefix = str.substr(0, i);
    string postfix = str.substr(n - i, i);

    if (prefix == postfix) {
      result = prefix;
    }
  }
  return result.empty() ? "empty" : result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    cout << matched_Prefix_postfix(str) << '\n';
  }
  return 0;
}