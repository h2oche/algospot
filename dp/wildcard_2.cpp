#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
#define endl '\n'
#define MAX_LEN 110
using namespace std;
typedef vector<string> vs;
typedef set<string> ss;

string w;
int n;
vs words;
int dp[MAX_LEN][MAX_LEN];

void init() {
  words.clear();
  cin >> w >> n;
  for(int i = 0 ; i < n ;i ++) {
    string str; cin >> str;
    words.push_back(str);
  }
}

void dp_init() {
  memset(dp, -1, sizeof dp);
}

bool is_null_string(int w_idx) {
  for(int i = w_idx; i < w.size() ; i ++)
    if(w[i] != '*')
      return false;
  return true;
}

int match(string& word, int w_idx, int word_idx) {
  if(dp[w_idx][word_idx] != -1)
    return dp[w_idx][word_idx];
  int& ret = dp[w_idx][word_idx];
  if(word_idx == word.size() && (w_idx == w.size() || is_null_string(w_idx)))
    return ret = 1;
  else if(w_idx == w.size() || word_idx == word.size())
    return ret = 0;
    
  if(word[word_idx] == w[w_idx] || w[w_idx] == '?')
    return ret = match(word, w_idx+1, word_idx+1);
  else if(w[w_idx] == '*')
    return ret = (match(word, w_idx+1, word_idx+1) || match(word, w_idx, word_idx+1) || match(word, w_idx+1, word_idx));
  else
    return ret = 0;
}

void solve() {
  init();

  ss ans;
  for(auto& word : words) {
    dp_init();
    if(match(word, 0, 0) == 1)
      ans.insert(word);
  }
  for(auto& s : ans)
    cout << s << endl;
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
