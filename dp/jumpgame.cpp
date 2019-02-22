#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 110
using namespace std;

int n,m;
int board[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];

void init() {
  memset(dp, 0, sizeof dp);
  memset(board, 0, sizeof board);

  cin >> n;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      cin >> board[i][j];
  dp[0][0] = 1;
}

bool check(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i >=n || j >= n) return false;
  return true;
}

void solve() {
  init();
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      if(dp[i][j] != 0) {
        if(check(i+board[i][j], j)) dp[i+board[i][j]][j] += dp[i][j];
        if(check(i, j+board[i][j])) dp[i][j+board[i][j]] += dp[i][j];
      }
    }
  }
  cout << (dp[n-1][n-1] > 0 ? "YES" : "NO") << endl;
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
