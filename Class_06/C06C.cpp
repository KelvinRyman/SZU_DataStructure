// DS二叉树–叶子数量
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    char *str = new char[10005];
    cin >> str;
    int count = 0;

    for (auto cur = str; *cur != '\0'; cur++) {
      if (*cur != '0' && cur[1] == '0' && cur[2] == '0') {
        count++, cur++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}