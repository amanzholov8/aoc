#include<bits/stdc++.h>
using namespace std;

bool inBound(int i) {
  return i >= 0 && i < 20;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s, numstr;
  int grid[20][20][20], x, y, z;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      for (int k = 0; k < 20; k++)
        grid[i][j][k] = 0;
  for (int i = 1; i <= 2170; i++) {
    getline(cin, s);
    numstr = s[0], s=s.substr(1);
    if (isdigit(s[0]))
      numstr += s[0], s = s.substr(1);
    s = s.substr(1);
    x = stoi(numstr);

    numstr = s[0], s=s.substr(1);
    if (isdigit(s[0]))
      numstr += s[0], s = s.substr(1);
    s = s.substr(1);
    y = stoi(numstr);

    numstr = s[0], s=s.substr(1);
    if (s.size() > 0)
      numstr += s[0];
    z = stoi(numstr);

    grid[x][y][z] = 1;
  }
  int ans = 0, cur;
  vector<vector<int>> neighs {
    {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}
  };
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      for (int k = 0; k < 20; k++) {
        if (grid[i][j][k] == 0)
          continue;
        cur = 6;
        for (vector<int> nei: neighs)
          if (inBound(i + nei[0]) && inBound(j + nei[1]) && inBound(k + nei[2]) && grid[i + nei[0]][j + nei[1]][k + nei[2]])
            cur--;
        ans += cur;
      }
    }
  }
  cout << ans << "\n";
}
