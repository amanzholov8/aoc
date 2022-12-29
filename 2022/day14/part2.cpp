#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int cave[510][1000];
  for (int i = 0; i < 510; i++) {
    for (int j = 0; j < 1000; j++) {
      cave[i][j] = 0;
    }
  }
  string s;
  string delimiter = " -> ";
  string strpath;
  vector<vector<int>> paths;
  int r, c, minR = 510;

  for (int i = 1; i <= 140 ; i++) {
    // process input line
    getline(cin, s);
    stringstream ss(s);
    while (ss >> strpath) {
      if (!isdigit(strpath[0]))
        continue;
      c = stoi(strpath.substr(0, strpath.find(",")));
      strpath.erase(0, s.find(",") + 1);
      r = stoi(strpath);
      if (r > 509 || c > 509)
        cout << "gg " << c << "," << r << "\n";
      paths.push_back({r, c});
      minR = min(minR, r);
    }
    // set cave to 1 based on paths
    for (int j = 1; j < paths.size(); j++) {
      if (paths[j][0] == paths[j-1][0]) {
        r = paths[j][0];
        for (int c = min(paths[j-1][1], paths[j][1]); c <= max(paths[j-1][1], paths[j][1]); c++)
          cave[r][c] = 1;
      }
      else {
        c = paths[j][1];
        for (int r = min(paths[j-1][0], paths[j][0]); r <= max(paths[j-1][0], paths[j][0]); r++)
          cave[r][c] = 1;
      }
    }
    paths.clear();
  }

  bool exists;
  int row;
  for (int r = 509; r >= minR; r--) {
    exists = false;
    for (int c = 0; c < 510; c++) {
      if (cave[r][c]) {
        exists = true;
        break;
      }
    }
    if (exists) {
      row = r + 2;
      break;
    }
  }
  for (int c = 0; c < 1000; c++)
    cave[row][c] = 1;


  int units = 0;
  int cr = 0, cc = 500;
  while (cr < 509 && cc > 0 && cc < 1499 && !cave[0][500]) {
    if (cave[cr + 1][cc] && cave[cr+1][cc-1] && cave[cr+1][cc+1]) {
      cave[cr][cc] = 1;
      units++, cr = 0, cc = 500;
      continue;
    }
    if (!cave[cr + 1][cc])
      cr++;
    else if (!cave[cr+1][cc-1])
      cr++, cc--;
    else if (!cave[cr+1][cc+1])
      cr++, cc++;
  }

  cout << units << "\n";
}
