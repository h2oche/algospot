#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 510
using namespace std;
typedef vector<int> vi;

int n;
int seq[MAX_N];
vi dp;

void init() {
  dp.clear();
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> seq[i];
  dp.push_back(seq[0]);
}

void solve() {
  init();
  for(int i = 1 ; i < n ; i ++) {
    if(dp.back() < seq[i])
      dp.push_back(seq[i]);
    else {
      auto it = lower_bound(dp.begin(), dp.end(), seq[i]);
      *it = seq[i];
    }
  }
        
  cout << dp.size() << endl;
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
