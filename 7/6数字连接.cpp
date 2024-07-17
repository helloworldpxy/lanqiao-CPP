#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
  ll n,x;cin>>n>>x;
  for(int i=0;i<n;i++)
  {
    string s1;cin>>s1;
    s+=s1;
  }
  ll ans=0;
  ll mul=1;
  for(int i=s.size()-1;i>=0;i--)
  {
    ans=ans+(s[i]-'0')*x*mul;
    mul=mul*10;
  }
  cout<<ans;
  return 0;
}
