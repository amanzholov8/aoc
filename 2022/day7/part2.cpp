#include<bits/stdc++.h>
using namespace std;

class node {
public:
  string name;
  int size;
  node* parent;
  node(string n = "", int s = 0, node* p = NULL) {
    name = n, size = s, parent = p;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  unordered_map<string, node*> mp;
  string s, name;
  node* cur = NULL;
  int size;
  for (int i = 1; i <= 1031; i++) {
    getline(cin, s);
    if (s == "$ cd ..") {
      cur = cur->parent;
    }
    else if (s == "$ ls")
      continue;
    else if (s.rfind("$ cd ", 0) == 0) {
      name = s.substr(5);
      if (name != "/")
        name = cur->name + name + "/";
      if (!mp.count(name))
        mp[name] = new node(name, 0, cur);
      cur = mp[name];
    } else if (s.rfind("dir ", 0) == 0) {
      name = cur->name + s.substr(4) + "/";
      mp[name] = new node(name, 0, cur);
    } else {
      stringstream ss(s);
      ss >> size >> name;
      for (auto p = cur; p; p = p->parent)
        p->size += size;
    }
  }

  int MAX = 70000000;
  int need = 30000000 - (MAX - mp["/"]->size);
  int res = MAX;

  for (auto x: mp) {
    if (x.second->size >= need)
      res = min(res, x.second->size);
    delete x.second;
  }
  cout << res << "\n";
}
