#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    stack<char> st;
    for (char& ch : str) {
      st.push(ch);
    }
    while (!st.empty()) {
      cout << st.top();
      st.pop();
    }
    cout << '\n';
  }
  return 0;
}