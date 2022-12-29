#include<bits/stdc++.h>
using namespace std;

string s;
int pushInd = 0; // modulo s.size()
int shapeStartInd, shapeEndInd;

bool touching(vector<vector<int>> heights) {
  for (int i = shapeStartInd; i <= shapeEndInd; i++)
    for (int j = 0; j < 7; j++)
      if (heights[i][j] == 1 && heights[i-1][j] == 2)
        return 1;
  return 0;
}

void down(vector<vector<int>>& heights) {
  for (int i = shapeStartInd; i <= shapeEndInd; i++) {
    for (int j = 0; j < 7; j++)
      if (heights[i][j] != 2 && heights[i-1][j] != 2)
        heights[i-1][j] = heights[i][j];
  }
  bool hasTower = false;
  for (int i = 0; i < 7; i++) {
    if (heights.back()[i] == 2) {
      hasTower = true;
      break;
    }
  }
  if (!hasTower)
    heights.pop_back();
  else {
    for (int i = 0; i < 7; i++)
      if (heights[shapeEndInd][i] == 1)
        heights[shapeEndInd][i] = 0;
  }
  shapeStartInd--, shapeEndInd--;
}

void moveRight(vector<vector<int>>& heights) {
  // check can move right
  for (int i = shapeStartInd; i <= shapeEndInd; i++) {
    if (heights[i][6] == 1)
      return;
    for (int j = 0; j < 6; j++)
      if (heights[i][j] == 1 && heights[i][j+1] == 2)
        return;
  }
  // move right
  int lastOneInd = -1;
  for (int i = shapeStartInd; i <= shapeEndInd; i++) {
    for (int j = 6; j > 0; j--)
      if (heights[i][j-1] == 1)
        heights[i][j] = 1, lastOneInd = j-1;
    if (lastOneInd != -1)
      heights[i][lastOneInd] = 0;
  }
}

void moveLeft(vector<vector<int>>& heights) {
  // check can move left
  for (int i = shapeStartInd; i <= shapeEndInd; i++) {
    if (heights[i][0] == 1)
      return;
    for (int j = 6; j > 0; j--)
      if (heights[i][j] == 1 && heights[i][j-1] == 2)
        return;
  }
  // move left
  int lastOneInd = -1;
  for (int i = shapeStartInd; i <= shapeEndInd; i++) {
    for (int j = 0; j < 6; j++)
      if (heights[i][j+1] == 1)
        heights[i][j] = 1, lastOneInd = j+1;
    if (lastOneInd != -1)
      heights[i][lastOneInd] = 0;
  }
}

void push(vector<vector<int>>& heights) {
  if (s[pushInd] == '>')
    moveRight(heights);
  else
    moveLeft(heights);
  pushInd++, pushInd %= s.size();
}

int main() {
  freopen("input2.txt", "r", stdin);
  getline(cin, s);
  long long blocks = 2022;
  vector<vector<int>> heights = {{2, 2, 2, 2, 2, 2, 2}};
  vector<vector<vector<int>>> shapes = {
    {{0, 0, 1, 1, 1, 1, 0}}, // line
    {{0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0}}, // plus
    {{0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}}, // linv
    {{0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}}, // vert
    {{0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}} // sqr
  };
  int shapeInd = 0; // modulo shapes.size()

  while (blocks > 0) {
    for (int i = 0; i < 3; i++)
      heights.push_back({0, 0, 0, 0, 0, 0, 0});
    shapeStartInd = heights.size();
    for (auto shape: shapes[shapeInd])
      heights.push_back(shape);
    shapeEndInd = heights.size() - 1;

    // if (blocks == 2021) {
    //   for (int i = 0; i < heights.size(); i++) {
    //     for (int j = 0; j < 7; j++)
    //       cout << heights[i][j] << " ";
    //     cout << "\n";
    //   }
    //   cout << "------\n";
    // }

    while (1) {
      push(heights);
      // if (blocks == 2021) {
      //   cout << "after push: \n";
      //   for (int i = 0; i < heights.size(); i++) {
      //     for (int j = 0; j < 7; j++)
      //       cout << heights[i][j] << " ";
      //     cout << "\n";
      //   }
      //   cout << "------\n";
      // }
      if (!touching(heights))
        down(heights);
      else
        break;
      // if (blocks == 2021) {
      //   cout << "after down: \n";
      //   for (int i = 0; i < heights.size(); i++) {
      //     for (int j = 0; j < 7; j++)
      //       cout << heights[i][j] << " ";
      //     cout << "\n";
      //   }
      //   cout << "------\n";
      // }
    }

    for (int i = shapeStartInd; i < heights.size(); i++)
      for (int j = 0; j < 7; j++)
        if (heights[i][j] == 1)
          heights[i][j] = 2;

    // if (blocks == 2021) {
    //   for (int i = 0; i < heights.size(); i++) {
    //     for (int j = 0; j < 7; j++)
    //       cout << heights[i][j] << " ";
    //     cout << "\n";
    //   }
    //   cout << "------\n";
    // }
    // cout << heights.size() - 1 << "\n";
    blocks--, shapeInd++, shapeInd %= shapes.size();
  }

  cout << heights.size() - 1 << "\n";
}