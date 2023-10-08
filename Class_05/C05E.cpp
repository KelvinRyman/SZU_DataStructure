// 子串循环问题(Ver. I)
#include <bits/stdc++.h>
using namespace std;

vector<int> getNextArr(string str) {
  int n = str.length();
  int i = 0, j = -1;
  vector<int> next(n + 1, 0);
  next[0] = -1;
  while (i < n) {
    if (j == -1 || str[i] == str[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }

  return next;
}

int findMinRepPeriodLength(const string &str) {
  int n = str.length();
  vector<int> next = getNextArr(str);
  int cir = n - next[n], adl;
  if (cir != n && n % cir == 0) {
    adl = 0;
  } else {
    adl = cir - n % cir;
  }
  return adl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    cout << findMinRepPeriodLength(str) << '\n';
  }
  return 0;
}