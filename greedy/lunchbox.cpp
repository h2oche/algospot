#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 100
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> buf;

void init() {
  cin >> n;
  buf = vector<pii>(n);
  for(int i = 0 ; i < n ; i++)
    cin >> buf[i].second;
  for(int i = 0 ; i < n ; i++)
    cin >> buf[i].first;
}

void solve() {
  init();

  sort(buf.begin(), buf.end(), [](const pii& a, const pii& b)->bool {
    return a.first > b.first;
  });

  int heat = 0;
  int lunch = 0;
  for(auto it = buf.begin(); it != buf.end() ; it++) {
    heat += (*it).second;
    lunch = max(lunch, heat + (*it).first);
  }
  
  cout << lunch << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ;i++)
    solve();
  return 0;
}
