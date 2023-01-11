#include<bits/stdc++.h>
using namespace std;

int rsize, csize, sr, sc, gr, gc;
vector<vector<int>> up, down, rright, lleft;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};
bool visited[1000][1000][1000];


bool empty(int r, int c, vector<vector<vector<int>>> bl) {
  if ((r == sr && c == sc) || (r == gr && c == gc))
  ////  if (r == gr && c == gc)
    return 1;
  if (r < 0 || c < 0 || r >= rsize || c >= csize)
    return 0;

  for (auto u: bl[0])
    if (r == u[0] && c == u[1])
      return 0;
  for (auto d: bl[1])
    if (r == d[0] && c == d[1])
      return 0;
  for (auto ri: bl[2])
    if (r == ri[0] && c == ri[1])
      return 0;
  for (auto l: bl[3])
    if (r == l[0] && c == l[1])
      return 0;
  return 1;
}

vector<vector<vector<int>>> move(vector<vector<vector<int>>> bl) {
  for (int i = 0; i < bl[0].size(); i++)
    bl[0][i] = {(bl[0][i][0] - 1 + rsize) % rsize, bl[0][i][1]};
  for (int i = 0; i < bl[1].size(); i++)
    bl[1][i] = {(bl[1][i][0] + 1) % rsize, bl[1][i][1]};
  for (int i = 0; i < bl[2].size(); i++)
    bl[2][i] = {bl[2][i][0], (bl[2][i][1] + 1) % csize};
  for (int i = 0; i < bl[3].size(); i++)
    bl[3][i] = {bl[3][i][0], (bl[3][i][1] - 1 + csize) % csize};
  return bl;
}

int main() {
  cout << "entering\n";
  freopen("input.txt", "r", stdin);
  cout << "here\n";
  string s;
  getline(cin, s);
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 1000; k++) {
        visited[i][j][k] = 0;
      }
    }
  }
  rsize = 35, csize = s.size() - 2;
  sr = -1, sc = 0, gr = 35, gc = s.size() - 3;
  for (int i = 0; i < rsize; i++) {
    getline(cin, s);
    for (int j = 1; j < s.size() - 1; j++) {
      if (s[j] == '^')
        up.push_back({i, j - 1});
      else if (s[j] == 'v')
        down.push_back({i, j - 1});
      else if (s[j] == '>')
        rright.push_back({i, j - 1});
      else if (s[j] == '<')
        lleft.push_back({i, j - 1});
    }
  }
  vector<vector<vector<vector<int>>>> boards;
  vector<vector<vector<int>>> bl = {up, down, rright, lleft};
  for (int i = 0; i <= rsize * csize; i++) {
    boards.push_back(bl);
    bl = move(bl);
  }
  int ans = 250;
  struct state {
    int cr, cc, depth;
    state(int r, int c, int d) {
      cr = r, cc = c, depth = d;
    }
  };
  queue<state> q;
  q.push(state(sr, sc, 0));
  int cr, cc, depth;
  cout << "gg\n";
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    cr = cur.cr, cc = cur.cc, depth = cur.depth;
//    cout << cr << " " << cc << " " << depth << " " << "\n";
    if (depth >= rsize * csize)   
      continue;
    if (cr == gr && cc == gc) {
      ans = min(ans, depth);
      cout << "temp ans: " << ans << "\n";
      continue;
    }
    if (visited[cr+1][cc][depth])
      continue;
    visited[cr+1][cc][depth] = 1;

    bl = boards[depth + 1];
    for (vector<int> dir: dirs)
      if (empty(cr + dir[0], cc + dir[1], bl)) {
        q.push(state(cr + dir[0], cc + dir[1], depth + 1));
      }
  }
  cout << ans << "\n";
}

