#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  int res = 0, cur = 0, n;
  for (int i=1; i<=2250; i++) {
    getline(cin, s);
    if (s.size() == 0) {
      res = max(res, cur), cur = 0;
      continue;
    }
    istringstream ss(s);
    ss >> n;
    cur += n;
  }
  cout<<res;
}