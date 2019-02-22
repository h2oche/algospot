#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 510
using namespace std;

int n;
int seq[MAX_N];
int dp[MAX_N];

void init() {
  memset(dp, 0, sizeof dp);
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> seq[i], dp[i] = 1;
}

void solve() {
  init();
  for(int i = 1 ; i < n ; i ++)
    for(int j = 0 ; j < i ; j ++)
      if(seq[j] < seq[i])
        dp[i] = max(dp[i], dp[j]+1);
        
  int ans = 0;
  for(int i = 0 ; i < n ; i ++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
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