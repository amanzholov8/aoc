#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  vector<char> invstacks[9];
  string s;
  for (int i = 1; i <= 8; i++) {
    getline(cin, s);
    for (int j = 0; j <= 8; j++) {
      if (s[1 + 4 * j] != ' ' && s[1 + 4 * j] != 0)
        invstacks[j].push_back(s[1 + 4 * j]);
    }
  }

  vector<char> stacks[9];
  for (int i = 0; i <= 8; i++) {
    while (invstacks[i].size() > 0) {
      stacks[i].push_back(invstacks[i].back());
      invstacks[i].pop_back();
    }
  }
  getline(cin, s); // unnecessary line

  int q, from, to;
  string dummy;
  char v;
  for (int i = 11; i <= 511; i++) {
    cin >> dummy >> q >> dummy >> from >> dummy >> to;
    for (int j = q; j >= 1; j--) {
      v = stacks[from - 1][stacks[from - 1].size() - j];
      stacks[to - 1].push_back(v);
    }
    for (int j = 1; j <= q; j++)
      stacks[from - 1].pop_back();
  }
  string msg = "";
  for (int i = 0; i <= 8; i++) {
    v = stacks[i].back();
    msg += v;
  }
  cout << msg << "\n";
}
