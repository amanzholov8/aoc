#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  long long sum = 0;
  string s;
  for (int i = 1; i <= 124; i++) {
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
      if (s[s.size() - 1 - i] == '=')
        sum -= 2 * pow(5, i);
      else if (s[s.size() - 1 - i] == '-')
        sum -= pow(5, i);
      else if (s[s.size() - 1 - i] == '1')
        sum += pow(5, i);
      else if (s[s.size() - 1 - i] == '2')
        sum += 2 * pow(5, i);

    }
  }

  string ans = "";
  while (sum != 0) {
    if (sum % 5 < 3)
      ans += to_string(sum % 5), sum /= 5;
    else if (sum % 5 == 3)
      ans += '=', sum = (sum + 2) / 5;
    else if (sum % 5 == 4)
      ans += '-', sum = (sum + 2) / 5;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
