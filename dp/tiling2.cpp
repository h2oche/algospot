#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MOD 1000000007
#define MAX_N 101
using namespace std;

int n;
int dp[MAX_N] = {0,};
int sum(int a, int b) {return (a%MOD+b%MOD)%MOD;}

void solve() {
  cin >> n;
  cout << dp[n] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;

  dp[1] = 1, dp[2] = 2;
  for(int i = 3 ; i < MAX_N ; i++)
    dp[i] = sum(dp[i-1], dp[i-2]);

  for(int i = 0 ; i < tc ; i ++)
    solve();
  
  return 0;
}
