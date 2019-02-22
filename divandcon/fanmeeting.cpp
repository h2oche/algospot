#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef vector<int> vll;

vll multiply_raw(vll& A, vll& B) {
  vll C = vll(A.size()*2-1, false);
  for(int i = 0 ; i < A.size(); i ++)
    for(int j = 0 ; j < B.size(); j++)
      C[i+j] += A[i] * B[j];
  return C;
}

vll add(vll& A, vll& B, bool sub) {
  vll C = A.size() > B.size() ? A : B;
  for(int i = 0 ; i < min(A.size(), B.size()); i++)
    C[i] = sub ? A[i] - B[i] : A[i] + B[i];
  return C;
}

vll multiply(vll& A, vll& B) {
  if(A.size() < 100) return multiply_raw(A, B);
  vll C = vll(A.size()*2-1, 0);
  
  int m = A.size() / 2;
  vll A0 = vll(m, 0);
  vll B0 = vll(m, 0);
  vll A1 = vll(A.size() - m, 0);
  vll B1 = vll(A.size() - m, 0);

  for(int i = 0 ; i < m ; i ++) {
    A0[i] = A[i];
    B0[i] = B[i];
  }

  for(int i = 0 ; i < A.size() - m ; i++) {
    A1[i] = A[m+i];
    B1[i] = B[m+i];
  }
  
  vll A2 = add(A0, A1, false);
  vll B2 = add(B0, B1, false);

  vll X0 = multiply(A0, B0);
  vll X1 = multiply(A1, B1);
  vll X2 = multiply(A2, B2);
  X2 = add(X2, X0, true);
  X2 = add(X2, X1, true);

  vll P1 = vll(2*m, 0);
  vll P2 = vll(m, 0);

  P1.insert(P1.end(), X1.begin(), X1.end());
  P2.insert(P2.end(), X2.begin(), X2.end());

  C = add(P1, P2, false);
  C = add(C, X0, false);

  return C;
}

string n, m;
void solve() {
  cin >> n >> m;
  int n_size = n.size(), m_size = m.size();
  if(n.size() > m.size())
    m += string(n.size() - m.size(), 'F');
  else if(m.size() > n.size())
    n += string(m.size() - n.size(), 'F');

  int len = n.size();
  vll A = vll(len, 0);
  vll B = vll(len, 0);

  for(int i = 0; i < len ; i++) {
    A[i] = (n[i] == 'M');
    B[len-1-i] = (m[i] == 'M');
  }

  auto C = multiply(A, B);

  int ans = 0;
  for(int i = n_size-1 ; i <= m_size-1 ; i++)
    if(C[i] == 0)
      ans++;

  cout << ans << endl;
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
