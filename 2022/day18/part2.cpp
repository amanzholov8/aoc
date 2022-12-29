#include<bits/stdc++.h>
using namespace std;

int grid[20][20][20];
int inside[20][20][20];
int visited[20][20][20];
int d = 20;
// int d = 7;

bool isInside(int x, int y, int z) {
  if (inside[x][y][z] != -1)
    return inside[x][y][z];
  if (visited[x][y][z])
    return 1;
  visited[x][y][z] = 1;
  int i = x - 1;
  while (i >= 0 && !grid[i][y][z]) {
    if (!isInside(i, y, z)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    i--;
  }
  if (i < 0 && !grid[0][y][z]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }
  i = x + 1;
  while (i < d && !grid[i][y][z]) {
    if (!isInside(i, y, z)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    i++;
  }
  if (i >= d && !grid[d-1][y][z]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }
  int j = y - 1;
  while (j >= 0 && !grid[x][j][z]) {
    if (!isInside(x, j, z)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    j--;
  }
  if (j < 0 && !grid[x][0][z]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }
  j = y + 1;
  while (j < d && !grid[x][j][z]) {
    if (!isInside(x, j, z)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    j++;
  }
  if (j >= d && !grid[x][d-1][z]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }
  int k = z - 1;
  while (k >= 0 && !grid[x][y][k]) {
    if (!isInside(x, y, k)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    k--;
  }
  if (k < 0 && !grid[x][y][0]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }
  k = z + 1;
  while (k < d && !grid[x][y][k]) {
    if (!isInside(x, y, k)) {
      visited[x][y][z] = 0;
      return inside[x][y][z] = 0;
    }
    k++;
  }
  if (k >= d && !grid[x][y][d-1]) {
    visited[x][y][z] = 0;
    return inside[x][y][z] = 0;
  }

  visited[x][y][z] = 0;
  return inside[x][y][z] = 1;
}

bool inBound(int i) {
  return i >= 0 && i < d;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s, numstr;
  int x, y, z;
  for (int i = 0; i < d; i++)
    for (int j = 0; j < d; j++)
      for (int k = 0; k < d; k++)
        grid[i][j][k] = 0, inside[i][j][k] = -1, visited[x][y][z] = 0;;
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
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      for (int k = 0; k < d; k++) {
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
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      for (int k = 0; k < d; k++) {
        if (grid[i][j][k] == 1 || !isInside(i, j, k))
          continue;
        cur = 0;
        for (vector<int> nei: neighs)
          if (inBound(i + nei[0]) && inBound(j + nei[1]) && inBound(k + nei[2]) && grid[i + nei[0]][j + nei[1]][k + nei[2]] == 1)
            cur++;
        ans -= cur;
      }
    }
  }
  cout << ans << "\n";
}
