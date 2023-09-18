#include <bits/stdc++.h>

using namespace std;

struct Position {
  int x, y;
  Position(int x = 0, int y = 0) : x(x), y(y) {}
};

bool isValid(const vector<vector<int>> &maze, vector<vector<bool>> &visited, int x, int y) {
  return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0 && !visited[x][y];
}

void solveMaze(const vector<vector<int>> &maze) {
  stack<Position> path;
  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
  Position offsets[4] = {Position(-1, 0), Position(1, 0), Position(0, -1), Position(0, 1)};
  path.push(Position(0, 0));
  visited[0][0] = true;

  while (!path.empty()) {
    Position pos = path.top();
    if (pos.x == maze.size() - 1 && pos.y == maze[0].size() - 1) break;

    bool deadend = true;
    for (int i = 0; i < 4; ++i) {
      Position next(pos.x + offsets[i].x, pos.y + offsets[i].y);
      if (isValid(maze, visited, next.x, next.y)) {
        path.push(next);
        visited[next.x][next.y] = true;
        deadend = false;
        break;
      }
    }

    if (deadend) path.pop();
  }

  stack<Position> path1;
  if (path.empty()) {
    cout << "no path" << endl;
  } else {
    while (!path.empty()) {
      path1.push(path.top());
      path.pop();
    }
    int count = 0;
    while (!path1.empty()) {
      Position cpos = path1.top();
      path1.pop();
      if (++count % 4 == 0) cout << '[' << cpos.x << ',' << cpos.y << ']' << "--\n";
      else cout << '[' << cpos.x << ',' << cpos.y << ']' << "--";
    }
    cout << "END\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> maze[i][j];
    solveMaze(maze);
  }
}
