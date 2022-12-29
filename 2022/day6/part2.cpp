#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int l = 0, r = 0;
  string s;
  unordered_map<char, int> count;
  getline(cin, s);
  while (r < s.size()) {
    count[s[r]]++;
    while (count[s[r]] > 1) {
      count[s[l]]--;
      if (count[s[l]] == 0)
        count.erase(s[l]);
      l++;
    }
    r++;
    if (count.size() == 14)
      break;
  }
  cout << r << "\n";
}
