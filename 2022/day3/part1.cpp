#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int res = 0;
  string r;
  unordered_set<char> seen;
  char extra;
  for (int i = 1; i <= 300; i++) {
    cin >> r;
    for (int j = 0; j < r.size() / 2; j++)
      seen.insert(r[j]);
    for (int j = r.size() / 2; j < r.size(); j++)
      if (seen.count(r[j]))
        extra = r[j];
    if (extra - 'a' + 1 > 0)
      res += extra - 'a' + 1;
    else
      res += extra - 'A' + 27;
    seen.clear();
  }
  cout << res << "\n";
}
