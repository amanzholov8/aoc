#include<bits/stdc++.h>
using namespace std;

int dist(char a, char b) {
  if (a == 'S')
    a = 'a';
  if (b == 'E')
    b = 'z';
  return b - a;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  vector<char> grid[41];
  for (int i = 0; i < 41; i++) {
    getline(cin, s);
    for (int j = 0; j < s.size(); j++)
      grid[i].push_back(s[j]);
  }

  struct item {
    int i, j, s;
    item(int r, int c, int st) {
      i = r, j = c, s = st;
    }
  };
  queue<item> q;
  bool visited[41][grid[0].size()];
  for (int i = 0; i < 41; i++)
    for (int j = 0; j < grid[0].size(); j++)
      visited[i][j] = false;
  q.push(item(20, 0, 0)); // i, j, step
  visited[20][0] = true;
  int i, j, st;
  int ans = 1e5;
  while (!q.empty()) {
    auto cur = q.front();
    i = cur.i, j = cur.j, st = cur.s;
    // cout << i << " " << j << " " << st << " " << visited[0][4] << "\n";
    q.pop();
    if (grid[i][j] == 'E') {
      ans = min(ans, st);
      continue;
    }
    if (i < 40 && !visited[i + 1][j] && dist(grid[i][j], grid[i+1][j]) <= 1) {
      q.push(item(i+1, j, st+1));
      visited[i+1][j] = true;
    }
    if (i > 0 && !visited[i - 1][j] && dist(grid[i][j], grid[i-1][j]) <= 1) {
      q.push(item(i-1, j, st+1));
      visited[i-1][j] = true;
    }
    if (j < grid[0].size() - 1 && !visited[i][j + 1] && dist(grid[i][j], grid[i][j+1]) <= 1) {
      q.push(item(i, j+1, st+1));
      visited[i][j+1] = true;
    }
    if (j > 0 && !visited[i][j-1] && dist(grid[i][j], grid[i][j-1]) <= 1) {
      q.push(item(i, j-1, st+1));
      visited[i][j-1] = true;
    }
  }
  cout << ans << "\n";
}
