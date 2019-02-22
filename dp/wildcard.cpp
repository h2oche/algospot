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

void init() {
  words.clear();
  cin >> w >> n;
  for(int i = 0 ; i < n ;i ++) {
    string str; cin >> str;
    words.push_back(str);
  }
}

bool is_null_string(int w_idx) {
  for(int i = w_idx; i < w.size() ; i ++)
    if(w[i] != '*')
      return false;
  return true;
}

bool match(string& word, int w_idx, int word_idx) {
  if(word_idx == word.size() && (w_idx == w.size() || is_null_string(w_idx)))
    return true;
  else if(w_idx == w.size() || word_idx == word.size())
    return false;

  if(word[word_idx] == w[w_idx] || w[w_idx] == '?')
    return match(word, w_idx+1, word_idx+1);
  else if(w[w_idx] == '*')
    return match(word, w_idx+1, word_idx+1) || match(word, w_idx, word_idx+1) || match(word, w_idx+1, word_idx);
  else
    return false;
}

void solve() {
  init();

  ss ans;
  for(auto& word : words)
    if(match(word, 0, 0))
      ans.insert(word);
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
