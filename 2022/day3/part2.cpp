#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int res = 0;
  string r;
  unordered_set<char> seen1, seen2;
  char badge;
  for (int i = 1; i <= 300; i+=3) {
    cin >> r;
    for (int j = 0; j < r.size(); j++)
      seen1.insert(r[j]);
    cin >> r;
    for (int j = 0; j < r.size(); j++)
      seen2.insert(r[j]);
    cin >> r;
    for (int j = 0; j < r.size(); j++)
      if (seen1.count(r[j]) && seen2.count(r[j]))
        badge = r[j];
    if (badge - 'a' + 1 > 0)
      res += badge - 'a' + 1;
    else
      res += badge - 'A' + 27;
    seen1.clear(), seen2.clear();
  }
  cout << res << "\n";
}
