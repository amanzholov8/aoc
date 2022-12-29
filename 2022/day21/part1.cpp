#include<bits/stdc++.h>
using namespace std;

unordered_map<string, long long> vals;
unordered_map<string, vector<string>> ops;

long long getAns(string node) {
  if (vals.count(node))
    return vals[node];
  if (ops[node][1] == "+")
    return vals[node] = getAns(ops[node][0]) + getAns(ops[node][2]);
  else if (ops[node][1] == "-")
    return vals[node] = getAns(ops[node][0]) - getAns(ops[node][2]);
  else if (ops[node][1] == "*")
    return vals[node] = getAns(ops[node][0]) * getAns(ops[node][2]);
  else
    return vals[node] = getAns(ops[node][0]) / getAns(ops[node][2]);
}

int main() {
  freopen("input.txt", "r", stdin);
  string s, node;
  for (int i = 1; i <= 1849; i++) {
    getline(cin, s);
    node = s.substr(0, 4);
    if (isdigit(s[6]))
      vals[node] = stoi(s.substr(6));
    else {
      ops[node].push_back(s.substr(6, 4));
      ops[node].push_back(s.substr(11, 1));
      ops[node].push_back(s.substr(13));
    }
  }

  long long ans = getAns("root");
  cout << ans << "\n";
}
