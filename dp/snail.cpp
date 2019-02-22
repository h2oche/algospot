#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define endl '\n'
#define MAX_LEN 1001
using namespace std;
typedef long double ld;

int n,m;
ld dp[MAX_LEN][MAX_LEN*2+1];

void init() {
  for(int i = 0 ; i < MAX_LEN; i++)
    for(int j = 0 ; j < MAX_LEN*2 + 1; j++)
      dp[i][j] = 2;
  cin >> n >> m;
}

ld climb(int day, int cur_height) {
  if(day == m) return cur_height >= n ? 1 : 0;
  if(abs(dp[day][cur_height] - 2) > 0.1) return dp[day][cur_height];
  return dp[day][cur_height] = 0.75 * climb(day+1, cur_height+2) + 0.25 * climb(day+1, cur_height+1);
}

void solve() {
  init();
  printf("%.10Lf\n", climb(0, 0));
}

int main()
{
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    solve();
  return 0;
}
