#include<bits/stdc++.h>
using namespace std;
#define ll long long

queue<ll> monkeys[8];
pair<bool, int> ops[8];
int tests[8];
int testT[8];
int testF[8];
int counts[8] = {0};
string s;
int v;
string op;

void getInputs(int i) {
  cin >> s;
  while (s != "*" && s != "+") {
    stringstream ss(s);
    ss >> v;
    monkeys[i].push(v);
    cin >> s;
  }
  cin >> op;
  if (op == "old")
    ops[i] = make_pair(s == "*", -1);
  else {
    stringstream ss(op);
    ss >> v;
    ops[i] = make_pair(s == "*", v);
  }
  cin >> tests[i] >> testT[i] >> testF[i];
}

int main() {
  freopen("input.txt", "r", stdin);
  int mod = 1;
  for (int i = 0; i < 8; i++) {
    getInputs(i);
    mod *= tests[i];
  }
  // for (int i = 0; i < 4; i++) {
  //   cout << monkeys[i].front() << "\n";
  //   cout << ops[i].first << " " << ops[i].second << "\n";
  //   cout << tests[i] << "\n";
  //   cout << testT[i] << "\n";
  //   cout << testF[i] << "\n\n";
  // }
  // return 0;
  ll v;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 8; j++) {
       while (!monkeys[j].empty()) {
        counts[j]++;
        v = monkeys[j].front(), monkeys[j].pop();
        if (ops[j].first == 0)
          v += (ops[j].second == -1) ? v : ops[j].second;
        else
          v *= (ops[j].second == -1) ? v : ops[j].second;
        v %= mod;
        if (v % tests[j] == 0)
          monkeys[testT[j]].push(v);
        else
          monkeys[testF[j]].push(v);
       }
    }
  }
  sort(counts, counts + 8, greater<ll>());
  cout << counts[0] << " " << counts[1] << "\n";
  cout << (ll) counts[0] * counts[1] << "\n";
}
