#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#define endl '\n'
#define MAX_N 20
using namespace std;
typedef pair<int,int> pii;

int n,m;
bool board[MAX_N][MAX_N] = {0,};
int empty_cnt;
pii blocks[4][2] = {
  {{1, 0}, {0, 1}},
  {{1, 0}, {1, 1}},
  {{0, 1}, {1, 1}},
  {{1, 0}, {1, -1}}
};

void init() {
  memset(board, false, sizeof board);
  cin >> n >> m;
  empty_cnt = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      char c; cin >> c;
      board[i][j] = c == '.' ? true : false;
      empty_cnt += c == '.' ? 1 : 0;
    }
  }
}

bool check(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i >= n || j >= m) return false;
  return board[i][j];
}

int count() {
  if(empty_cnt % 3 != 0) return 0;

  // find top, left
  int top = -1, left = -1;
  for(int i = 0 ; i < n ; i ++ ) {
    bool found = false;
    for(int j = 0 ; j < m ; j ++ ) {
      if(board[i][j]) {
        top = i, left = j;
        found = true;
        break;
      }
    }
    if(found) break;
  }
  // filled
  if(top == -1 && left == -1) return 1;

  // search
  int ret = 0;
  board[top][left] = false;
  for(int i = 0 ; i < 4 ; i++) {
    bool search_next = true;
    for(int j = 0 ; j < 2 ; j ++)
      if(!check(top + blocks[i][j].first, left + blocks[i][j].second))
        search_next = false;
    if(!search_next) continue;

    for(int j = 0 ; j < 2 ; j ++)
      board[top + blocks[i][j].first][left + blocks[i][j].second] = false;
    ret += count();
    for(int j = 0 ; j < 2 ; j ++)
      board[top + blocks[i][j].first][left + blocks[i][j].second] = true;
  }
  board[top][left] = true;
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
