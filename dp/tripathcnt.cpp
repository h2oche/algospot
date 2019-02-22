#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#define endl '\n'
#define MAX_N 110
using namespace std;
typedef pair<int,int> pii;

int n;
int tri[MAX_N][MAX_N] = {0,};
pii dp[MAX_N][MAX_N];

void init() {
  memset(tri, 0, sizeof tri);
  memset(dp, 0, sizeof dp);
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j <= i ; j ++)
      cin >> tri[i][j];
  dp[0][0] = pii(tri[0][0], 1);
}

void solve() {
  init();
  
  for(int i = 1 ; i < n ; i++) {
    for(int j = 0; j <= i; j++) {
      pii& left = dp[i-1][j-1];
      pii& top = dp[i-1][j];
      
      if(left.first == top.first)
        dp[i][j] = pii(left.first+tri[i][j], left.second+top.second);
      else if(left.first > top.first)
        dp[i][j] = pii(left.first+tri[i][j], left.second);
      else
        dp[i][j] = pii(top.first+tri[i][j], top.second);
    }
  }

  int ans = 0;
  int max_val = 0;
  for(int i = 0 ; i < n ; i ++) {
    if(max_val < dp[n-1][i].first) {
      max_val = dp[n-1][i].first;
      ans = dp[n-1][i].second;
    } else if (max_val == dp[n-1][i].first) {
      ans += dp[n-1][i].second;
    }
  }
  
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
