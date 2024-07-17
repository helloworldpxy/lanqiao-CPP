#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =1e6+4;
const int p=1e9+7;
ll a[N],pre[N];
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)pre[i]=pre[i-1]^a[i];
  ll ans=1;
  for(int i=1;i<=n;++i)
    for(int j=i;j<=n;++j)
    {
      ll t=pre[i-1]^pre[j];
      if(!t)
      {
          cout<<0;
          return 0;
      }
      ans=ans*(t)%p;
    }   
  cout<<ans;
  return 0;
}
