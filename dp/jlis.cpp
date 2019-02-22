#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#define endl '\n'
#define MAX_LEN 110
using namespace std;
typedef long long ll;

int n,m;
int A[MAX_LEN], B[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];

void init() {
  memset(dp, -1, sizeof dp);

  cin >> n >> m;
  for(int i = 0 ; i < n ; i ++)
    cin >> A[i];
  for(int i = 0 ; i < m ; i ++)
    cin >> B[i];
}

int jlis(int a, int b) {
  int& ret = dp[a+1][b+1];
  if(ret != -1) return ret;
  
  ll A_val = (a == -1 ? LONG_MIN : A[a]);
  ll B_val = (b == -1 ? LONG_MIN : B[b]);
  ll max_val = max(A_val, B_val);

  ret = 2;
  for(int i = a + 1; i < n ; i ++)
    if(max_val < A[i])
      ret = max(ret, jlis(i, b) + 1);
  for(int i = b + 1 ; i < m ; i ++)
    if(max_val < B[i])
      ret = max(ret, jlis(a, i) + 1);
  return ret;
}

void solve() {
  init();
  cout << (jlis(-1, -1) - 2) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc; i ++)
    solve();
  return 0;
}
