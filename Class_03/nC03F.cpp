#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isValidMove(int x, int y, int n, const vector<vector<int>> &maze) {
  return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0;
}

struct Position {
  int xp, yp;
  Position(int x, int y) : xp(x), yp(y) {}
};

void findPath(const vector<vector<int>> &maze) {
  int n = static_cast<int>(maze.size());
  stack<Position> stack;
  stack.emplace(0, 0);
  vector<Position> path;
  vector<Position> path1;

  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  Position start(0, 0);
  Position end(n - 1, n - 1);

  while (!stack.empty()) {
    Position current = stack.top();
    stack.pop();
    path.push_back(current);

    if (current.xp == end.xp && current.yp == end.yp) {
      while (!path.empty()) {
        path1.push_back(path.back());
        path.pop_back();
      }
    }

    bool found = false;
    for (const auto &dir : directions) {
      int nx = current.xp + dir.first;
      int ny = current.yp + dir.second;
      if (isValidMove(nx, ny, n, maze)) {
        stack.emplace(nx, ny);
        found = true;
      }
    }

    if (!found) {
      path.pop_back();
    }
  }

  if (!path1.empty()) {
    int i = 0;
    while (!path1.empty()) {
      Position cpos = path1.back();
      path1.pop_back();
      if ((i + 1) % 4 == 0) {
        cout << "[" << cpos.xp << "," << cpos.yp << "]--" << endl;
      } else {
        cout << "[" << cpos.xp << "," << cpos.yp << "]--";
      }
      i++;
    }
    cout << "END" << endl;
  } else {
    cout << "no path" << endl;
  }
}

int main() {
  int t;
  cin >> t;  // 迷宫数量
  while (t--) {
    int n;
    cin >> n;  // 迷宫尺寸
    vector<vector<int>> maze(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> maze[i][j];
      }
    }
    findPath(maze);
  }
  return 0;
}