#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {
  {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};
vector<vector<int>> elfs;
vector<vector<int>> newElfs;

bool isEmpty(vector<int> elf) {
  for (vector<int> dir: dirs) {
    for (vector<int> elfc: elfs) {
      if (elfc[0] == elf[0] + dir[0] && elfc[1] == elf[1] + dir[1])
        return 0;
    }
  }
  return 1;
}

bool isDuplicate(vector<int> elf) {
  int count = 0;
  for (vector<int> nelf: newElfs) {
    if (elf[0] == nelf[0] && elf[1] == nelf[1])
      count++;
  }
  return count > 1;
}

bool contains(vector<int> elf) {
  for (vector<int> elfc: elfs) {
    if (elf[0] == elfc[0] && elf[1] == elfc[1])
      return 1;
  }
  return 0;
}

vector<int> getNewPos0(vector<int> elf) {
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[1][0], elf[1] + dirs[1][1]}) && !contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}))
    return {elf[0] - 1, elf[1]};
  if (!contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}) && !contains({elf[0] + dirs[6][0], elf[1] + dirs[6][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0] + 1, elf[1]};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[3][0], elf[1] + dirs[3][1]}) && !contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}))
    return {elf[0], elf[1] - 1};
  if (!contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}) && !contains({elf[0] + dirs[4][0], elf[1] + dirs[4][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0], elf[1] + 1};
  return elf;
}

vector<int> getNewPos1(vector<int> elf) {
  if (!contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}) && !contains({elf[0] + dirs[6][0], elf[1] + dirs[6][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0] + 1, elf[1]};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[3][0], elf[1] + dirs[3][1]}) && !contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}))
    return {elf[0], elf[1] - 1};
  if (!contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}) && !contains({elf[0] + dirs[4][0], elf[1] + dirs[4][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0], elf[1] + 1};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[1][0], elf[1] + dirs[1][1]}) && !contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}))
    return {elf[0] - 1, elf[1]};
  return elf;
}

vector<int> getNewPos2(vector<int> elf) {
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[3][0], elf[1] + dirs[3][1]}) && !contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}))
    return {elf[0], elf[1] - 1};
  if (!contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}) && !contains({elf[0] + dirs[4][0], elf[1] + dirs[4][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0], elf[1] + 1};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[1][0], elf[1] + dirs[1][1]}) && !contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}))
    return {elf[0] - 1, elf[1]};
  if (!contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}) && !contains({elf[0] + dirs[6][0], elf[1] + dirs[6][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0] + 1, elf[1]};
  return elf;
}

vector<int> getNewPos3(vector<int> elf) {
  if (!contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}) && !contains({elf[0] + dirs[4][0], elf[1] + dirs[4][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0], elf[1] + 1};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[1][0], elf[1] + dirs[1][1]}) && !contains({elf[0] + dirs[2][0], elf[1] + dirs[2][1]}))
    return {elf[0] - 1, elf[1]};
  if (!contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}) && !contains({elf[0] + dirs[6][0], elf[1] + dirs[6][1]}) && !contains({elf[0] + dirs[7][0], elf[1] + dirs[7][1]}))
    return {elf[0] + 1, elf[1]};
  if (!contains({elf[0] + dirs[0][0], elf[1] + dirs[0][1]}) && !contains({elf[0] + dirs[3][0], elf[1] + dirs[3][1]}) && !contains({elf[0] + dirs[5][0], elf[1] + dirs[5][1]}))
    return {elf[0], elf[1] - 1};
  return elf;
}

int main() {
  freopen("input.txt", "r", stdin);
  string s;
  for (int i = 0; i < 73; i++) {
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '#')
        elfs.push_back({i, j});
    }
  }
  cout << elfs.size() << "\n";

  vector<vector<int>> duplicates;
  for (int i = 0; i < 10; i++) {
    for (vector<int> elf: elfs) {
      if (isEmpty(elf))
        newElfs.push_back(elf);
      else if (i % 4 == 0)
        newElfs.push_back(getNewPos0(elf));
      else if (i % 4 == 1)
        newElfs.push_back(getNewPos1(elf));
      else if (i % 4 == 2)
        newElfs.push_back(getNewPos2(elf));
      else
        newElfs.push_back(getNewPos3(elf));
    }

    for (vector<int> nelf: newElfs)
      if (isDuplicate(nelf))
        duplicates.push_back(nelf);
    for (int e = 0; e < newElfs.size(); e++) {
      for (vector<int> dup: duplicates) {
        if (newElfs[e][0] == dup[0] && newElfs[e][1] == dup[1]) {
          newElfs[e] = elfs[e];
          break;
        }
      }
    }
    elfs = newElfs;
    newElfs.clear(), duplicates.clear();
  }

  int minr = 10000, maxr = -10000, minc = 10000, maxc = -10000;
  for (vector<int> elf: elfs) {
    minr = min(minr, elf[0]), maxr = max(maxr, elf[0]);
    minc = min(minc, elf[1]), maxc = max(maxc, elf[1]);
  }
  cout << minr << " " << maxr << "\n";
  cout << minc << " " << maxc << "\n";
  cout << elfs.size() << "\n";
  int ans = (maxr - minr + 1) * (maxc - minc + 1) - elfs.size();
  cout << ans << "\n";
}
