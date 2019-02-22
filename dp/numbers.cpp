#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_LEN 101
using namespace std;
typedef long double ld;

int n,d,p,t;
double A[MAX_LEN][MAX_LEN];
ld dp[MAX_LEN][MAX_LEN];
int B[MAX_LEN];

void init() {
  for(int i = 0 ; i < MAX_LEN ; i++)
    for(int j = 0 ; j < MAX_LEN; j ++)
      dp[i][j] = 0.0;

  cin >> n >> d >> p;
  for(int i = 0 ; i < n ; i ++) {
    int cnt = 0;
    for(int j = 0 ; j < n ; j ++) {
      cin >> A[i][j];
      if(A[i][j] == 1.0) cnt++;
    }
    for(int j = 0 ; j < n ; j ++)
      if(A[i][j] == 1.0)
        A[i][j] = A[i][j] / cnt;
  }
  cin >> t;
  for(int i = 0 ; i < t ; i++)
    cin >> B[i];

  dp[0][p] = 1.0;
}

void solve() {
  init();
  
  for(int i = 0 ; i < d ; i ++) {
    for(int j = 0 ; j < n ; j ++) {
      if(dp[i][j] == 0.0) continue;
      for(int k = 0 ; k < n ; k ++)
        dp[i+1][k] += dp[i][j] * A[j][k];
    }
  }

  for(int i = 0 ; i < t ; i ++)
    printf("%.10Lf ", dp[d][B[i]]);
  printf("\n");
}

int main()
{
  int tc; cin >> tc;
  for(int i = 0 ;i < tc ;i ++)
    solve();
  return 0;
}
