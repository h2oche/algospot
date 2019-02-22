#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 30000
using namespace std;

int n;
int fence[MAX_N] = {0,};

void init() {
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> fence[i];
}

int max_area(int start, int end) {
  if(start >= end) return 0;
  if(start + 1 == end) return fence[start];
  int m = (start+end)/2;
  int area = max_area(start, m);
  area = max(area, max_area(m, end));
  
  int low = m-1, high = m, h = min(fence[m-1], fence[m]);
  area = max(area, 2 * h);

  while(low > start || high < end - 1) {
    if(high < end - 1 && fence[low-1] < fence[high+1]) {
      high++;
      h = min(h, fence[high]);
    } else {
      low--;
      h = min(h, fence[low]);
    }
    area = max(area, (high-low+1)*h);
  }

  return area;
}

void solve() {
  init();
  cout << max_area(0, n) << endl;
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
