#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> vals;
unordered_map<string, vector<string>> neighs;
unordered_map<
  string,
  unordered_map<
    int,
    pair<
      int,
      unordered_map<string, int>
    >
  >
> memo;

int getAns(string cur, int time) {
  if (time  <= 2)
    return 0;
  int res = 0, temp;
  if (memo.count(cur) && memo[cur].count(time) && memo[cur][time].second == vals)
    return memo[cur][time].first;
  for (string nei: neighs[cur]) {
    if (vals.count(nei) && time > 2) {
      temp = vals[nei], vals.erase(nei);
      res = max(res, (time - 2) * temp + getAns(nei, time - 2));
      vals[nei] = temp;
    }
    res = max(res, getAns(nei, time - 1));
  }
  memo[cur][time] = make_pair(res, vals);
  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s, name, nei;
  int val;
  for (int i = 1; i <= 56; i++) {
    getline(cin, s);
    stringstream ss(s);
    ss >> name >> val;
    if (val > 0)
      vals[name] = val;
    ss >> nei;
    while (neighs[name].size() == 0 || nei != neighs[name].back()) {
      neighs[name].push_back(nei), ss >> nei;
    }
  }
  int total = getAns("AA", 30);
  cout << total << "\n";
}
