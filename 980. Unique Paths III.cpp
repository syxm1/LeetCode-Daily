class Solution {
private:
  int ans = 0, start_x, start_y, finish_x, finish_y, cnt_zero = 0, n, m;
  const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
  vector<vector<bool>> is_visited;

  bool is_afinished(int x, int y) { return x == finish_x && y == finish_y; }

  bool is_inside(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

  int traverse(int cur_x, int cur_y, int cur_dist, vector<vector<int>> &grid) {
    if (is_finished(cur_x, cur_y)) {
      return cur_dist == cnt_zero;
    }

    int ret = 0;

    for (int i = 0; i < 4; i++) {
      int nxt_x = cur_x + dx[i];
      int nxt_y = cur_y + dy[i];

      if (!is_inside(nxt_x, nxt_y))
        continue;
      if (grid[nxt_x][nxt_y] == -1)
        continue;
      if (grid[nxt_x][nxt_y] == 1)
        continue;
      if (grid[nxt_x][nxt_y] == 2 && cnt_zero != cur_dist)
        continue;
      if (is_visited[nxt_x][nxt_y])
        continue;

      int nxt_dist = cur_dist + (grid[nxt_x][nxt_y] == 0);

      is_visited[nxt_x][nxt_y] = true;
      ret += traverse(nxt_x, nxt_y, nxt_dist, grid);
      is_visited[nxt_x][nxt_y] = false;
    }

    return ret;
  }

public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    is_visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0)
          cnt_zero++;
        if (grid[i][j] == 1)
          start_x = i, start_y = j;
        if (grid[i][j] == 2)
          finish_x = i, finish_y = j;
      }
    }

    return traverse(start_x, start_y, 0, grid);
  }
};
