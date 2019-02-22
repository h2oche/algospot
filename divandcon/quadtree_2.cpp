#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

string reverse(string::iterator& it) {
  char c = *(it++);
  if(c == 'b' || c == 'w') return string(1,c);
  string first = reverse(it);
  string second = reverse(it);
  string third = reverse(it);
  string fourth = reverse(it);
  return "x" + third + fourth + first + second;
}

void solve() {
  string qt; cin >> qt;
  auto it = qt.begin();
  cout << reverse(it) << endl;
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
