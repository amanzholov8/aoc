#include<bits/stdc++.h>
using namespace std;

inline uint64_t key(int i,int j) {return (uint64_t) i << 32 | (unsigned int) j;}

int main() {
  freopen("input.txt", "r", stdin);
  set<pair<int, int>> empty;
  string s;
  int sx, sy, bx, by, dist, ldist;
  int minx, miny, maxx, maxy;
  int mx = 0;
  // int y = 10;
  int y = 2000000;
  for (int t = 1; t <= 32; t++) {
    getline(cin, s);
    stringstream ss(s);
    ss >> sx >> sy >> bx >> by;
    mx = max(mx, sx), mx = max(mx, sy), mx = max(mx, bx), mx = max(mx, by);
    dist = abs(sx - bx) + abs(sy - by);
    minx = sx - dist, maxx = sx + dist;
    // miny = sy - dist, maxy = sy + dist;
    for (int i = minx; i <= maxx; i++) {
      ldist = abs(sx - i) + abs(sy - y);
      if (ldist <= dist && (i != bx || y != by))
        empty.insert(make_pair(i, y));
    }
  }
  int ans = empty.size();
  cout << ans << "\n";
}
