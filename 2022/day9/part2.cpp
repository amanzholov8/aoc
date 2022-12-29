#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pi pair<int, int>
#define f first
#define s second

vector<pi> knots(10, mp(0, 0));

void doubleDiagonal(int j) {
  if (knots[j+1].f - knots[j].f == 2 && knots[j+1].s - knots[j].s == 2)
    knots[j] = mp(knots[j].f + 1, knots[j].s + 1);
  else if (knots[j+1].f - knots[j].f == -2 && knots[j+1].s - knots[j].s == 2)
    knots[j] = mp(knots[j].f - 1, knots[j].s + 1);
  else if (knots[j+1].f - knots[j].f == 2 && knots[j+1].s - knots[j].s == -2)
    knots[j] = mp(knots[j].f + 1, knots[j].s - 1);
  else if (knots[j+1].f - knots[j].f == -2 && knots[j+1].s - knots[j].s == -2)
    knots[j] = mp(knots[j].f - 1, knots[j].s - 1);
}

void doubleVertical(int j) {
  if (knots[j+1].f - knots[j].f == 2)
    knots[j] = mp(knots[j].f + 1, knots[j+1].s);
  else if (knots[j+1].f - knots[j].f == -2)
    knots[j] = mp(knots[j].f - 1, knots[j+1].s);
}

void doubleHorizontal(int j) {
  if (knots[j+1].s - knots[j].s == 2)
    knots[j] = mp(knots[j+1].f, knots[j].s + 1);
  else if (knots[j+1].s - knots[j].s == -2)
    knots[j] = mp(knots[j+1].f, knots[j].s - 1);
}

int main() {
  freopen("input.txt", "r", stdin);
  char d;
  int c;
  set<pair<int, int>> visited;

  visited.insert(mp(0, 0));
  for (int i = 1; i <= 2000; i++) {
    cin >> d >> c;
    if (d == 'R' || d == 'L') {
      for (int st = 0; st < c; st++) {
        (d == 'R') ? knots[9].s++ : knots[9].s--;
        for (int j = 8; j >= 0; j--) {
          doubleDiagonal(j);
          doubleVertical(j);
          doubleHorizontal(j);
        }
        visited.insert(knots[0]);
      }
    } else {
      for (int st = 0; st < c; st++) {
        (d == 'U') ? knots[9].f++ : knots[9].f--;
        for (int j = 8; j >= 0; j--) {
          doubleDiagonal(j);
          doubleHorizontal(j);
          doubleVertical(j);
        }
        visited.insert(knots[0]);
      }
    }
  }
  cout << visited.size() << "\n";
}
