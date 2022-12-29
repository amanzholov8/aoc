#include<bits/stdc++.h>
using namespace std;

struct node {
  int type; // 0 - int, 1 - vector
  int val;
  queue<node*> vals;
  node* parent;
};

void process(string s, node* n) {
  node* cur;
  node* parent = n;
  int i = 0;
  string num = "";
  while (i < s.size()) {
    while (i < s.size() && isdigit(s[i])) {
      num += s[i], i++;
    }
    if (num.size() > 0) {
      cur = new node();
      cur->type = 0, cur->val = stoi(num), cur->parent = parent;
      num = "";
      parent->vals.push(cur);
    }
    if (s[i] == '[') {
      cur = new node();
      cur->type = 1, cur->parent = parent;
      parent->vals.push(cur);
      parent = cur;
    } else if (s[i] == ']') {
      parent = parent->parent;
    }
    i++;
  }
}

int compare(node* n1, node* n2) {
  if (n1->type == 0 && n2->type == 0) {
    // cout << n1->val << " " << n2->val << "\n";
    if (n1->val < n2->val)
      return -1;
    else if (n1->val > n2->val)
      return 1;
    return 0;
  }
  if (n1->type == 0) {
    node* temp = new node();
    temp->type = 1;
    temp->vals.push(n1);
    n1 = temp;
  }
  if (n2->type == 0) {
    node* temp = new node();
    temp->type = 1;
    temp->vals.push(n2);
    n2 = temp;
  }

  if (n1->vals.empty())
    return -1;
  while (!n1->vals.empty()) {
    if (n2->vals.empty())
      return 1;
    node* cur1 = n1->vals.front();
    node* cur2 = n2->vals.front();
    n1->vals.pop(), n2->vals.pop();
    int res = compare(cur1, cur2);
    if (res == -1)
      return -1;
    else if (res == 1)
      return 1;
  }
  if (!n2->vals.empty())
    return -1;
  return 0;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s1, s2;
  node* n1, *n2;
  int ans = 0, cur = 1;
  for (int i = 1; i < 450; i+= 3) {
    n1 = new node();
    n2 = new node();
    n1->type = 1, n2->type = 1;
    getline(cin, s1), getline(cin, s2);
    // cout << s1 << "\n" << s2 << "\n";
    process(s1, n1), process(s2, n2);

    // cout <<"gg\n";
    // if (cur == 5)
    //   cout << compare(n1, n2) << "\n";
    if (compare(n1, n2) == -1) {
      // cout << cur << "\n";
      ans += cur;
    }
    // if (cur == 2)
    //   break;
    cur++;
    getline(cin, s1); // empty line
  }
  cout << ans << "\n";
}
