#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int cycle = 0, x = 1, res = 0;
  string cmd;
  int v;
  for (int i = 1; i <= 143; i++) {
    cin >> cmd;
    cycle++;
    if ((cycle - 20) % 40 == 0)
      res += cycle * x;
    if (cmd == "addx") {
      cin >> v;
      cycle++;
      if ((cycle - 20) % 40 == 0)
        res += cycle * x;
      x += v;
    }
  }
  cout << res << "\n";
}
