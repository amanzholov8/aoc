#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int score = 0;
  char s1, s2;
  // s1: A - rock, B - paper, C - scissors
  // s2: X - rock, Y - paper, Z - scissors

  for (int i = 1; i <= 2500; i++) {
    cin >> s1 >> s2;
    score += (s2 - 'X' + 1);
    if (s1 - 'A' + 1 ==  s2 - 'X' || s1 - 'A' - 2 ==  s2 - 'X')
      score += 6;
    if (s1 - 'A' == s2 - 'X')
      score += 3;
  }
  cout << score;
}
