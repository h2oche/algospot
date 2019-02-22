#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int resolve(string& qt, int idx) {
  if(qt[idx] == 'b' || qt[idx] == 'w') return idx + 1;
  int res = resolve(qt, idx+1);
  res = resolve(qt, res);
  res = resolve(qt, res);
  res = resolve(qt, res);
  return res;
}

string reverse(string qt) {
  if(qt.size() == 1) return qt;
  if(qt.size() == 5) return qt.substr(0,1) + qt.substr(3, 2) + qt.substr(1, 2);
  int first = resolve(qt, 1);
  int second = resolve(qt, first);
  int third = resolve(qt, second);
  return "x" + reverse(qt.substr(second, third-second)) + reverse(qt.substr(third, qt.size() - third))
            + reverse(qt.substr(1, first-1)) + reverse(qt.substr(first, second - first));
}

void solve() {
  string qt; cin >> qt;
  cout << reverse(qt) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i++)
    solve();
  return 0;
}
