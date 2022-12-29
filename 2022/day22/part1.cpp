#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  int len = 200;
  vector<string> grid;
  for (int i = 1; i <= len; i++) {
    getline(cin, s);
    grid.push_back(s);
  }
  int row = 0, face = 0, col = 0;
  while (grid[0][col] != '.')
    col++;

  getline(cin, s), getline(cin, s);
  int del, ind, prevRow, prevCol;
  while(s.size() != 0) {
    ind = 0;
    while (isdigit(s[ind]))
      ind++;
    del = stoi(s.substr(0, ind));
    s = s.substr(ind);

    while (del > 0) {
      if (face == 0) {
        prevCol = col;
        col++, col %= grid[row].size();
        while (grid[row][col] == ' ')
          col++, col %= grid[row].size();
        if (grid[row][col] == '#')
          col = prevCol, del = 0;
      } else if (face == 2) {
        prevCol = col;
        col--, col = (col + grid[row].size()) % grid[row].size();
        while (grid[row][col] == ' ')
          col--, col = (col + grid[row].size()) % grid[row].size();
        if (grid[row][col] == '#')
          col = prevCol, del = 0;
      } else if (face == 1) {
        prevRow = row;
        row++, row %= len;
        while (col >= grid[row].size() || grid[row][col] == ' ')
          row++, row %= len;
        if (grid[row][col] == '#')
          row = prevRow, del = 0;
      } else {
        prevRow = row;
        row--, row = (row + len) % len;
        while (col >= grid[row].size() || grid[row][col] == ' ')
          row--, row = (row + len) % len;
        if (grid[row][col] == '#')
          row = prevRow, del = 0;
      }
      del--;
    }

    if (s.size() == 0)
      break;
    if (s[0] == 'R')
      face++, face %= 4;
    else
      face--, face = (face + 4) % 4;
    s = s.substr(1);
  }

  cout << row << " " << col << " " << face << "\n";
  int ans = 1000 * (row + 1) + 4 * (col + 1) + face;
  cout << ans << "\n";
}
