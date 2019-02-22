#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_LEN 110
using namespace std;

int n,m;
int A[MAX_LEN], B[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int dp_a[MAX_LEN];
int dp_b[MAX_LEN];

void init() {
  memset(dp, -1, sizeof dp);
  memset(dp_a, -1, sizeof dp_a);
  memset(dp_b, -1, sizeof dp_b);

  cin >> n >> m;
  for(int i = 0 ; i < n ; i ++)
    cin >> A[i];
  for(int i = 0 ; i < m ; i ++)
    cin >> B[i];
}

int lis_a(int a) {
  if(dp_a[a] != -1) return dp_a[a];
  if(a == n-1) return dp_a[a] = 1;
  else {
    int ret = 1;
    for(int i = a+1; i < n ; i++)
      if(A[a] < A[i])
        ret = max(ret, 1 + lis_a(i));
    return dp_a[a] = ret;
  }
}

int lis_b(int b) {
  if(dp_b[b] != -1) return dp_b[b];
  if(b == m-1) return dp_b[b] = 1;
  else {
    int ret = 1;
    for(int i = b+1; i < m ; i++)
      if(B[b] < B[i])
        ret = max(ret, 1 + lis_b(i));
    return dp_b[b] = ret;
  }
}

int jlis(int a, int b) {
  if(a == n-1) {
    int ret = 1;
    for(int i = b; i < m ; i++) {
      if(A[a] < B[i])
        ret = max(ret, 1 + lis_b(i));
      else if(A[a] == B[i])
        ret = max(ret, lis_b(i));
    }
    return dp[a][b] = ret;
  }
  else if(b == m-1) {
    int ret = 1;
    for(int i = a; i < n ; i++) {
      if(B[b] < A[i])
        ret = max(ret, 1 + lis_a(i));
      else if(B[b] == A[i])
        ret = max(ret, lis_a(i));
    }
    return dp[a][b] = ret;
  }

  if(A[a] < B[b]) {
    int ret = 2;
    for(int i = a+1 ; i < n ; i ++) {
      if(A[a] < A[i]) {
        if(A[i] <= B[b])
          ret = max(ret, jlis(i, b) + 1);
        else {
          for(int j = b+1; j < m ; j ++) {
            if(B[b] < B[j])
              ret = max(ret, jlis(i, j) + 2);
          }
        }
      }
    }
    return dp[a][b] = ret;
  }

  else if(B[b] < A[a]) {
    int ret = 2;
    for(int i = b+1 ; i < m ; i ++) {
      if(B[b] < B[i]) {
        if(B[i] <= A[a])
          ret = max(ret, jlis(a, i) + 1);
        else {
          for(int j = a+1; j < n ; j++) {
            if(A[a] < A[j])
              ret = max(ret, jlis(j, i) + 2);
          }
        }
      }
    }
    return dp[a][b] = ret;
  }
  else {
    int ret = 1;
    for(int i = a+1; i < n ; i ++)
      for(int j = b+1; j < m ; j++)
        if(A[a] < A[i] && B[b] < B[j])
        ret = max(ret, jlis(i,j)+1);
    return dp[a][b] = ret;
  }
}

void solve() {
  init();
  int ans = 0;
  for(int i = 0 ; i < n ; i ++)
    for(int j = 0 ; j < m ; j++)
      ans = max(ans, jlis(i, j));
  cout << ans << endl;
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
