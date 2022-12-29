#include<bits/stdc++.h>
using namespace std;

struct node {
  int type; // 0 - int, 1 - vector
  int val;
  int cur = 0;
  vector<node*> vals;
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
      parent->vals.push_back(cur);
    }
    if (s[i] == '[') {
      cur = new node();
      cur->type = 1, cur->parent = parent;
      parent->vals.push_back(cur);
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
  node* temp = new node();
  if (n1->type == 0) {
    temp->type = 1;
    temp->vals.push_back(n1);
    n1 = temp;
  }
  if (n2->type == 0) {
    temp->type = 1;
    temp->vals.push_back(n2);
    n2 = temp;
  }

  if (n1->cur == n1->vals.size()) {
    n1->cur = 0, n2->cur = 0;
    delete temp;
    return -1;
  }
  while (n1->cur != n1->vals.size()) {
    if (n2->cur == n2->vals.size()) {
      n1->cur = 0, n2->cur = 0;
      delete temp;
      return 1;
    }
    node* cur1 = n1->vals[n1->cur];
    node* cur2 = n2->vals[n2->cur];
    n1->cur++, n2->cur++;
    int res = compare(cur1, cur2);
    if (res == -1) {
      n1->cur = 0, n2->cur = 0;
      delete temp;
      return -1;
    }
    else if (res == 1) {
      n1->cur = 0, n2->cur = 0;
      delete temp;
      return 1;
    }
  }
  delete temp;
  if (n2->cur != n2->vals.size()) {
    n1->cur = 0, n2->cur = 0;
    return -1;
  }
  n1->cur = 0, n2->cur = 0;
  return 0;
}

void bubbleSort(vector<node*>& packets) {
  bool isSorted = false;
  int lastUnsorted = (int) packets.size() - 1;
  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < lastUnsorted; i++)
      if (compare(packets[i], packets[i+1]) != -1) {
        swap(packets[i], packets[i+1]);
        isSorted = false;
      }
    lastUnsorted--;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  string s1, s2;
  node* n1, *n2;
  vector<node*> packets;
  for (int i = 1; i < 450; i+= 3) {
    n1 = new node();
    n2 = new node();
    n1->type = 1, n2->type = 1;
    getline(cin, s1), getline(cin, s2);
    process(s1, n1), process(s2, n2);
    packets.push_back(n1), packets.push_back(n2);
    getline(cin, s1); // empty line
  }
  n1 = new node();
  n2 = new node();
  n1->type = 1, n2->type = 1;
  s1 = "[[2]]", s2 = "[[6]]";
  process(s1, n1), process(s2, n2);
  packets.push_back(n1), packets.push_back(n2);

  bubbleSort(packets);

  int ind1, ind2;
  for (int i = 0; i < packets.size(); i++) {
    if (packets[i] == n1)
      ind1 = i + 1;
    if (packets[i] == n2)
      ind2 = i + 1;
  }
  cout << ind1 * ind2 << "\n";

  for (auto p: packets)
    delete p;
}
