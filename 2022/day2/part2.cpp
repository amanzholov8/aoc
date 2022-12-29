#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int score = 0;
  char s1, s2;
  // s1: A - rock, B - paper, C - scissors
  // s2: X - lose, Y - draw, Z - win

  for (int i = 1; i <= 2500; i++) {
    cin >> s1 >> s2;
    score += (s2 - 'X') * 3;
    score += (s1 - 'A' + s2 - 'X' + 2) % 3 + 1;
  }
  cout << score;
}
