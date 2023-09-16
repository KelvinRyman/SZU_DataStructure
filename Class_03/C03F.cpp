#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> maze[i][j];
  vector<vector<int>> vis(n, vector<int>(n, 0));

  stack<point> path, temp;
  path.push({0, 0});
  vis[0][0] = 1;

  while (!path.empty()) {
    point top = path.top();
    if (top.x == n - 1 && top.y == n - 1) break;

    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      int nx = top.x + dx[i], ny = top.y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] == 0 && !vis[nx][ny]) {
        path.push({nx, ny});
        vis[nx][ny] = 1;
        flag = true;
        break;
      }
    }

    if (!flag) path.pop();
  }

  while (!path.empty()) {
    temp.push(path.top());
    path.pop();
  }

  int i = 0;
  while (!temp.empty()) {
    point cpos = temp.top();
    temp.pop();
    if (++i % 4 == 0) cout << '[' << cpos.x << ',' << cpos.y << ']' << "--\n";
    else cout << '[' << cpos.x << ',' << cpos.y << ']' << "--";
  }

  if (i == 0) cout << "no path\n";
  else cout << "END\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}