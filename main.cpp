#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int n,m;
int clocks[16] = {0,};
int sw[10][5] = {
  {0,1,2,-1,-1},
  {3,7,9,11,-1},
  {4,10,14,15,-1},
  {0,4,5,6,7},
  {6,7,8,10,12},
  {0,2,14,15,-1},
  {3,14,15,-1,-1},
  {4,5,7,14,15},
  {1,2,3,4,5},
  {3,4,5,9,13}
};

int press_arr[10] = {0,};

void press(int sw_idx, int cnt, bool reverse) {
  for(int i = 0 ; i < 5 && sw[sw_idx][i] != -1; i++)
    clocks[sw[sw_idx][i]] = (clocks[sw[sw_idx][i]] + (reverse ? 9 : 3) * cnt) % 12;
}

bool check() {
  for(int i = 0 ; i < 16 ; i++)
    if(clocks[i] != 0)
      return false;
  return true;
}

int cost() {
  int ret = 0;
  for(int i = 0 ; i < 10 ; i++)
    ret += press_arr[i];
  return ret;
}

void init() {
  for(int i = 0 ; i < 16 ; i++)
    cin >> clocks[i];
  for(int i = 0 ; i < 16 ; i++)
    clocks[i] = clocks[i] % 12;
}

int find_min(int cur_idx) {
  if(cur_idx == 10) {
    for(int i = 0 ; i < 10 ; i ++)
      press(i, press_arr[i], false);
    int ret = check() ? cost() : -1;
    for(int i = 0 ; i < 10 ; i ++)
      press(i, press_arr[i], true);
    return ret;
  }

  int ret = -1;
  for(int i = 0 ; i < 4 ; i++) {
    press_arr[cur_idx] = i;
    int res = find_min(cur_idx+1);
    if(res != -1) {
      if(ret == -1) ret = res;
      else ret = min(res, ret);
    }
  }

  return ret;
}

void solve() {
  init();
  cout << find_min(0) << endl;
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
