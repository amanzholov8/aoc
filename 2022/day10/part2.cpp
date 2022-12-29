#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int cycle = 0, x = 1;
  string res = "";
  string cmd;
  int v;
  for (int i = 1; i <= 143; i++) {
    cin >> cmd;
    res += (abs(cycle - x) <= 1) ? "#" : ".";
    cycle++, cycle %= 40;
    if (cycle == 0)
      res += "\n";
    if (cmd == "addx") {
      cin >> v;
      res += (abs(cycle - x) <= 1) ? "#" : ".";
      cycle++, cycle %= 40;
      if (cycle == 0)
        res += "\n";
      x += v;
    }
  }
  cout << res << "\n";
}
