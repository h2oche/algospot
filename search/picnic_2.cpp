#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;
typedef set<int> si;

int n,m;
vector<pii> pairs;

void init() {
  pairs.clear();
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    int a, b; cin >> a >> b;
    pairs.push_back(pii(min(a, b), max(a, b)));
  }
  sort(pairs.begin(), pairs.end());
}

bool checkMaked(vector<pii>& maked) {
  for(auto m : maked)
    if(count(pairs.begin(), pairs.end(), m) == 0)
      return false;
  return true;
}

int count(vector<pii>& maked, si& left) {
  if(left.size() == 2) {
    maked.push_back(pii(*left.begin(), *left.rbegin()));
    int ret = checkMaked(maked) ? 1 : 0;
    maked.pop_back();
    return ret;
  }

  int ret = 0;
  int first = *left.begin();
  left.erase(first);
  auto it = left.begin();
  for(; it != left.end();it++) {
    int second = *it;
    maked.push_back(pii(first, second));
    left.erase(it);
    ret += count(maked, left);
    it = left.insert(second).first;
    maked.pop_back();
  }
  left.insert(first);
  return ret;
}

void solve() {
  init();
  vector<pii> maked;
  si left;
  for(int i = 0 ; i < n ; i++)
    left.insert(i);
  cout << count (maked, left) << endl;
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
