#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define endl '\n'
#define MAX_N 110
#define INF 987654321
using namespace std;
typedef pair<int,int> pii;

int n,m;
int seq[MAX_N];
int dp[MAX_N][MAX_N][11];
vector<pii> comp;

void init() {
  comp.clear();
  memset(dp, -1, sizeof dp);

  cin >> n >> m;
  for(int i = 0 ; i < n ; i ++)
    cin >> seq[i];
  sort(seq, seq+n);

  int streak = 1;
  for(int i = 0 ; i < n ; i ++) {
    if(i == n-1 || seq[i] != seq[i+1]) {
      comp.push_back(pii(seq[i], streak));
      streak = 1;
    }
    else streak++;
  }
}

int mse(int start, int end, int cap) {
  if(cap == 0) return INF;
  
  if(dp[start][end][cap] != -1)
    return dp[start][end][cap];
  if(cap >= end - start)
    return dp[start][end][cap] = 0;
  if(cap == 1) {
    int sum = 0, cnt = 0;
    for(int i = start; i < end; i++) {
      sum += comp[i].first * comp[i].second;
      cnt += comp[i].second;
    }
    int key = floor((double)sum/cnt + 0.5);
    int val = 0;
    for(int i = start; i < end; i++) {
      int err = abs(comp[i].first - key);
      val += comp[i].second * err * err;
    }
    return dp[start][end][cap] = val;
  }
  
  int ret = INF;
  for(int m = start+1; m < end; m++)
    for(int k = 1; k < cap ; k ++)
      ret = min(ret, mse(start, m, k) + mse(m, end, cap-k));

  return dp[start][end][cap] = ret;
}

void solve() {
  init();
  cout << mse(0, comp.size(), m) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    solve();
  return 0;
}
