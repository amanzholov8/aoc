#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  vector<int> res;
  int cur = 0, n;
  for (int i=1; i<=2250; i++) {
    getline(cin, s);
    if (s.size() == 0) {
      res.push_back(cur), cur = 0;
      continue;
    }
    istringstream ss(s);
    ss >> n;
    cur += n;
  }
  sort(res.begin(), res.end(), greater<int>());
  cout << res[0] + res[1] + res[2];
}