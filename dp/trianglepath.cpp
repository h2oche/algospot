#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 110
using namespace std;

int n;
int tri[MAX_N][MAX_N] = {0,};
int dp[MAX_N][MAX_N] = {0,};

void init() {
  memset(tri, 0, sizeof tri);
  memset(dp, 0, sizeof dp);
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j <= i ; j ++)
      cin >> tri[i][j];
  dp[0][0] = tri[0][0];
}

void solve() {
  init();
  
  for(int i = 1 ; i < n ; i++)
    for(int j = 0; j <= i; j++)
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];

  int ans = 0;
  for(int i = 0 ; i < n ; i ++)
    ans = max(dp[n-1][i], ans);
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
