#include<bits/stdc++.h>
using namespace std;

int sz;

bool check(int mat[][1000], int r, int c) {
  int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
  for (int i = r - 1; i >= 0; i--) {
    if (mat[i][c] >= mat[r][c]) {
      check1 = 1;
      break;
    }
  }
  for (int i = r + 1; i < 99; i++) {
    if (mat[i][c] >= mat[r][c]) {
      check2 = 1;
      break;
    }
  }
  for (int j = c - 1; j >= 0; j--) {
    if (mat[r][j] >= mat[r][c]) {
      check3 = 1;
      break;
    }
  }
  for (int j = c + 1; j < sz; j++) {
    if (mat[r][j] >= mat[r][c]) {
      check4 = 1;
      break;
    }
  }
  return (check1 && check2 && check3 && check4);
}

int main() {
  freopen("input.txt", "r", stdin);
  int res = 97 * 2;
  string s;
  getline(cin, s);
  sz = s.size();
  res += sz * 2;
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
      if (!check(mat, i, j))
        res++;
    }
  }
  cout << res << "\n";
}
