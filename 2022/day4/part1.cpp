#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  int r1, r2, r3, r4;
  int res = 0;
  for (int i = 1; i <= 1000; i++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-' || s[i] == ',')
        s[i] = ' ';
    }
    stringstream ss(s);
    ss >> r1 >> r2 >> r3 >> r4;
    if (r1 <= r3 && r2 >= r4)
      res++;
    else if (r3 <= r1 && r4 >= r2)
      res++;
  }
  cout << res << "\n";
}
