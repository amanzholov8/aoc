#include<bits/stdc++.h>
using namespace std;

int sz;
int res = 0;

void check(int mat[][1000], int r, int c) {
  int cur1 = 0, cur2 = 0, cur3 = 0, cur4 = 0;
  for (int i = r - 1; i >= 0; i--) {
    cur1++;
    if (mat[i][c] >= mat[r][c]) {
      break;
    }
  }
  for (int i = r + 1; i < 99; i++) {
    cur2++;
    if (mat[i][c] >= mat[r][c]) {
      break;
    }
  }
  for (int j = c - 1; j >= 0; j--) {
    cur3++;
    if (mat[r][j] >= mat[r][c]) {
      break;
    }
  }
  for (int j = c + 1; j < sz; j++) {
    cur4++;
    if (mat[r][j] >= mat[r][c]) {
      break;
    }
  }
  res = max(res, cur1 * cur2 * cur3 * cur4);
}

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  getline(cin, s);
  sz = s.size();
  int mat[99][1000];
  for (int j = 0; j < sz; j++) {
    mat[0][j] = s[j] - '0';
  }
  for (int i = 1; i < 99; i++) {
    getline(cin, s);
    for (int j = 0; j < sz; j++) {
      mat[i][j] = s[j] - '0';
    }
  }
  for (int i = 1; i < 98; i++) {
    for (int j = 1; j < sz - 1; j++) {
      check(mat, i, j);
    }
  }
  cout << res << "\n";
}
