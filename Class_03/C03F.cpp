#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const int &x, const int &y, const int &n, const vector<vector<int>> &maze) {
  return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0;
}

struct Point {
  int x, y;
};

stack<Point> path;
string output_path;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool findThePath(const int &n, const vector<vector<int>> &maze) {
  bool visited[n][n];
  Point start = {0, 0};
  Point end = {n - 1, n - 1};

  stack<Point> path1;
  stack<Point> st;
  st.push(start);
  visited[start.x][start.y] = true;

  while (!st.empty()) {
    Point curr = st.top();
    st.pop();
    path.push(curr);
    path1.push(curr);

    if (curr.x == end.x && curr.y == end.y) {
      int count = 0;
      while (!path1.empty()) {
        Point p = path1.top();
        path1.pop();
        output_path += "[" + to_string(p.x) + ", " + to_string(p.y) + "]" + "--";
        count++;
        if (count % 4 == 0) {
          output_path += '\n';
        }
      }
//      reverse(output_path.begin(), output_path.end());
      output_path += "END";
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];
      if (isValid(nx, ny, n, maze) && !visited[nx][ny]) {
        Point next = {nx, ny};
        st.push(next);
        visited[nx][ny] = true;
      }
    }
  }

  return false;
}

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
        cin >> maze[i][j];
      }
    }
    bool status = findThePath(n, maze);
    if (status) {
      cout << output_path;
    } else {
      cout << "no path";
    }
  }
  return 0;
}