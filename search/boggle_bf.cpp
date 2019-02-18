#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;
typedef vector<string> vs;

char board[5][5] = {0,};
int n;
vs words;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void init() {
  words.clear();
  for(int i = 0 ; i < 5 ; i++)
    for(int j = 0 ; j < 5 ; j++)
      cin >> board[i][j];
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    string str; cin >> str;
    words.push_back(str);
  }
}

bool check(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i > 4 || j > 4) return false;
  return true;
}

bool searchRec(string& word, int i, int j, int cur) {
  if(cur == word.size()) return true;
  if(!check(i, j)) return false;
  if(word[cur] != board[i][j]) return false;
  bool ret = false;
  for(int a = 0 ; a < 8 && !ret ; a++)
    ret |= searchRec(word, i + dy[a], j + dx[a], cur + 1);
  return ret;
}

bool search(string& word) {
  for(int i = 0 ; i < 5 ; i++)
    for(int j = 0 ; j < 5 ; j++)
      if(searchRec(word, i, j, 0))
        return true;
  return false;
}

void solve() {
  init();
  for(auto& w : words)
    cout << w << ' ' << (search(w) ? "YES" : "NO") << endl;
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
