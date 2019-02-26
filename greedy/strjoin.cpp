#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
#define MAX_N 100
using namespace std;

int n;
multiset<int> files;

void init() {
  cin >> n;
  files.clear();
  for(int i = 0 ; i < n ; i++) {
    int file; cin >> file;
    files.insert(file);
  }
}

void solve() {
  init();
  int ans = 0;
  while(files.size() > 1) {
    auto it = files.begin();
    int a = *it;
    files.erase(it);

    it = files.begin();
    int b = *it;
    files.erase(it);

    ans += a+b;
    files.insert(a+b);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ;i++)
    solve();
  return 0;
}
