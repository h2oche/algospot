#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 10
using namespace std;

int n,m;
bool pairs[MAX_N][MAX_N] = {0,};
bool used[MAX_N] = {0,};

void init() {
  memset(pairs, false, sizeof pairs);
  memset(used, false, sizeof used);
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    int a, b; cin >> a >> b;
    pairs[a][b] = true;
    pairs[b][a] = true;
  }
}

int count() {
  int smallest = -1;
  for(int i = 0 ; i < n ; i++) {
    if(!used[i]) {
      smallest = i;
      break;
    }
  }
  if(smallest == -1) return 1;

  int ret = 0;
  used[smallest] = true;
  for (int i = smallest + 1 ; i < n ; i++) {
    if(!used[i] && pairs[smallest][i]) {
      used[i] = true;
      ret += count();
      used[i] = false;
    }
  }
  used[smallest] = false;
  return ret;
}

void solve() {
  init();
  cout << count() << endl;
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
