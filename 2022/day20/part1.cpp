#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  unordered_set<int> moved;
  int len = 5000, del = 100000;
  int nums[5000];
  for (int i = 1; i <= len; i++) {
    cin >> nums[i-1];
  }
  int ind, dInd;
  while(moved.size() != len) {
    ind = 0;
    while (moved.count(nums[ind])) {
      ind++;
    }

    if (nums[ind] >= 0) {
      dInd = ind + nums[ind];
      while (dInd >= len)
        dInd = (dInd + 1) - len;
      dInd %= len;
    }
    else {
      dInd = (ind + nums[ind] - 1 + len);
      while (dInd < 0)
        dInd += len - 1;
      dInd %= len;
    }

    while (ind != dInd) {
      if (ind < dInd)
        swap(nums[ind], nums[ind + 1]), ind++;
      else if (ind > dInd)
        swap(nums[ind], nums[ind - 1]), ind--;
    }

    if (nums[ind] >= 0)
      nums[ind] += del;
    else
      nums[ind] -= del;
    while (moved.count(nums[ind])) {
      if (nums[ind] >= 0)
        nums[ind] += del;
      else
        nums[ind] -= del;
    }
    moved.insert(nums[ind]);

  }

  ind = 0;
  while (nums[ind] % del != 0)
    ind++;
  int ans = 0;
  cout << nums[(ind + 1000) % len] << "\n";
  cout << nums[(ind + 2000) % len] << "\n";
  cout << nums[(ind + 3000) % len] << "\n";
  ans += nums[(ind + 1000) % len] % del + nums[(ind + 2000) % len] % del + nums[(ind + 3000) % len] % del;
  cout << ans << "\n";
}
