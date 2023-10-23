// DS 串应用 — 最长重复子串
#include <bits/stdc++.h>
using namespace std;

int longestRepSubStrLength(const string &str) {
  int n = str.length();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  int maxLength = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (str[i - 1] == str[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        maxLength = max(maxLength, dp[i][j]);
      }
    }
  }

  return maxLength > 0 ? maxLength : -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;

    cout << longestRepSubStrLength(str) << '\n';
  }
  return 0;
}