#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MOD 10000000
#define MAX_N 101
using namespace std;

int n,m;
int dp[MAX_N][MAX_N] = {0,};
int sum(int a, int b) {return (a%MOD+b%MOD)%MOD;}
int mul(int a, int b) {return ((long long)(a%MOD)*(b%MOD))%MOD;}

void solve() {
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n ; i++)
    ans = sum(ans, dp[n][i]);
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i = 1 ; i < MAX_N; i ++)
    dp[i][i] = 1;

  for(int i = 2; i < MAX_N; i ++)
    for(int j = 1; j < i ; j++)
      for(int k = 1; k <= i-j; k++)
        dp[i][j] = sum(dp[i][j], mul(dp[i-j][k], k+j-1));

  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    solve();
  
  return 0;
}
