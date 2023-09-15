//
// Created by myour on 2023/9/13.
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    string str;
    getline(cin, str);
    stack<char> st;
    for (char &ch: str) {
      if (ch != '#') {
        st.push(ch);
      } else {
        if (!st.empty()) {
          st.pop();
        }
      }
    }

    int count = 0;
    string result;
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }
    if (!result.empty()) {
      reverse(result.begin(), result.end());
      cout << result << '\n';
    } else {
      cout << "NULL\n";
    }
  }
  return 0;
}