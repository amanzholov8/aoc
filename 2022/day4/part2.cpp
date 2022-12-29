#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  int l1, l2, r1, r2;
  int res = 0;
  for (int i = 1; i <= 1000; i++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-' || s[i] == ',')
        s[i] = ' ';
    }
    stringstream ss(s);
    ss >> l1 >> l2 >> r1 >> r2;
    if (l1 <= r1 && r1 <= l2)
      res++;
    else if (r1 <= l1 && l1 <= r2)
      res++;
  }
  cout << res << "\n";
}
