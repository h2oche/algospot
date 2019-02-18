#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

typedef vector<int> vi;

int n,m;

void printPicked(vi& picked) {
  for(auto i : picked)
    cout << i << ' ';
  cout << endl;
}

void pick(vi& picked, int toPick) {
  if(toPick == 0)
    printPicked(picked);
  else {
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int i = smallest ; i < n ; i++) {
      picked.push_back(i);
      pick(picked, toPick-1);
      picked.pop_back();
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vi picked;
  pick(picked, m);
  return 0;
}
