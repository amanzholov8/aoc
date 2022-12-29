#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pi pair<int, int>
#define f first
#define s second

int main() {
  freopen("input.txt", "r", stdin);
  char d;
  int c;
  set<pair<int, int>> visited;
  pi head = mp(0, 0), tail = mp(0, 0);
  visited.insert(tail);
  for (int i = 1; i <= 2000; i++) {
    cin >> d >> c;
    if (d == 'R') {
      for (int st = 0; st < c; st++) {
        head.s++;
        if (abs(head.s - tail.s) == 2) {
          tail = mp(head.f, tail.s + 1);
          visited.insert(tail);
        }
      }
    } else if (d == 'L') {
      for (int st = 0; st < c; st++) {
        head.s--;
        if (abs(head.s - tail.s) == 2) {
          tail = mp(head.f, tail.s - 1);
          visited.insert(tail);
        }
      }
    } else if (d == 'U') {
      for (int st = 0; st < c; st++) {
        head.f++;
        if (abs(head.f - tail.f) == 2) {
          tail = mp(tail.f + 1, head.s);
          visited.insert(tail);
        }
      }
    } else {
      for (int st = 0; st < c; st++) {
        head.f--;
        if (abs(head.f - tail.f) == 2) {
          tail = mp(tail.f - 1, head.s);
          visited.insert(tail);
        }
      }
    }
  }
  cout << visited.size() << "\n";
}
