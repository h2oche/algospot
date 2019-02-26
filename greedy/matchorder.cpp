#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 100
using namespace std;

int n;
int rus[MAX_N];
int kor[MAX_N];

void init() {
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> rus[i];
  for(int i = 0 ; i < n ; i++)
    cin >> kor[i];
}

void solve() {
  init();

  sort(rus, rus+n);
  sort(kor, kor+n);

  int ans = 0;
  for(int i = n - 1, j = n - 1 ; i >= 0 && j >=0; ) {
    if(kor[i] >= rus[j]) i--, j--, ans++;
    else j--;
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
