#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MOD 1000000007
#define MAX_N 101
using namespace std;
typedef pair<int, int> pii;

int n,m;
int sum(int a, int b) {return (a%MOD+b%MOD)%MOD;}
pii dp[MAX_N];

void solve() {
  cin >> n;
  cout << sum(dp[n].first, MOD - dp[n].second) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  dp[1] = pii(1,1);
  dp[2] = pii(2,2);
  dp[3] = pii(3,1);
  dp[4] = pii(5,3);

  for(int i = 5; i < MAX_N; i ++)
    dp[i] = pii(sum(dp[i-1].first, dp[i-2].first), sum(dp[i-2].second, dp[i-4].second));

  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    solve();
  
  return 0;
}
