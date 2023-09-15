//
// Created by myour on 2023/9/13.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    stack<char> st;
    bool error_flag = false;
    for (char &ch: str) {
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);
      } else if (ch == ')' && st.top() == '(') {
        st.pop();
      } else if (ch == ']' && st.top() == '[') {
        st.pop();
      } else if (ch == '}' && st.top() == '{') {
        st.pop();
      } else if (ch == ')' || ch == ']' || ch == '}') {
        cout << "error" << endl;
        break;
      }
    }
    if (!st.empty()) {
      cout << "error\n";
      error_flag = true;
    }
    if (!error_flag) {
      cout << "ok\n";
    }
  }
  return 0;
}