#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int n;
  string a , b;
  cin >> n >> a >> b;
  int ans1 = 0 , ans2 = 0;
  int k = 0;
  for(int i = a.size() - 1 ; i >= 0 ; i--)
  {
    ans1 += (a[i] - '0') * pow(n , k);
    k++;
  }
  k = 0;
  for(int i = b.size() - 1 ; i >= 0 ; i--)
  {
    ans2 += (b[i] - '0') * pow(n , k);
    k++;
  }
  cout << ans1 * ans2;
  return 0;
}
