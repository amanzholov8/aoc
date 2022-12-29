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
  unordered_map<string, long long> lvals;
  unordered_map<string, vector<string>> lops;
  for (int i = 1; i <= 1849; i++) {
    getline(cin, s);
    node = s.substr(0, 4);
    if (isdigit(s[6]))
      lvals[node] = stoi(s.substr(6));
    else {
      lops[node].push_back(s.substr(6, 4));
      lops[node].push_back(s.substr(11, 1));
      lops[node].push_back(s.substr(13));
    }
  }
  long long i = 3592056845000;
  vals = lvals, ops = lops;
  vals["humn"] = i;
  long long ans1 = getAns(ops["root"][0]), ans2 = getAns(ops["root"][2]);
  cout << ans1 << " " << ans2 << "\n";
  while (ans1 != ans2) {
    vals = lvals, ops = lops;
    i++, vals["humn"] = i;
    ans1 = getAns(ops["root"][0]);
    cout << ans1 << " " << ans2 << "\n";
  }
  cout << i << "\n";
}
