#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    stack<char> st;
    bool error_flag = false;
    for (char &ch : str) {
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);
      } else if (ch == ')' && !st.empty() && st.top() == '(' ) {
        st.pop();
      } else if (ch == ']' && !st.empty() && st.top() == '[') {
        st.pop();
      } else if (ch == '}' && !st.empty() && st.top() == '{') {
        st.pop();
      } else if (ch == ')' || ch == ']' || ch == '}') {
        cout << "error" << endl;
        error_flag = true;
        break;
      } else {
        continue;
      }
    }

    if (error_flag) continue;
    if (!st.empty()) {
      cout << "error\n";
      continue;
    }
    cout << "ok\n";
  }
  return 0;
}