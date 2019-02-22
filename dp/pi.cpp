#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define endl '\n'
#define MAX_N 10010
#define INT_MAX 1000000000
using namespace std;

int n,m;
int dp[MAX_N];
string pi;

void init() {
  cin >> pi;
  for(int i = 0 ; i < pi.size() ; i ++)
    dp[i] = INT_MAX;
}

int level(int idx, int length) {
  bool equal = true, mono = true, alter = true, seq = true;
  for(int i = idx; i < idx+length; i ++) {
    if(i < idx+length-1 && pi[i] != pi[i+1])
      equal = false;
    if(i < idx+length-2) {
      if(pi[i+1] - pi[i] != pi[i+2] - pi[i+1])
        mono = seq = false;
      else if(abs(pi[i+1] - pi[i]) != 1)
        mono = false;
      if(pi[i] != pi[i+2])
        alter = false;
    }
  }
  if(equal) return 1;
  if(mono) return 2;
  if(alter) return 4;
  if(seq) return 5;
  return 10;
}

int level_sum(int idx) {
  int left = pi.size() - idx;
  if(dp[idx] != INT_MAX) return dp[idx];

  if(left < 3) return dp[idx] = INT_MAX - 1;
  else if(left <= 5) return dp[idx] = level(idx, left);

  for(int l = 3 ; l <= 5 ; l++)
    dp[idx] = min(level(idx, l) + level_sum(idx+l), dp[idx]);
  return dp[idx];
}

void solve() {
  init();
  cout << level_sum(0) << endl;
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
