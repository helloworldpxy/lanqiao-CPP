#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main()
{
    long long n,q,l,r,x;
    long long s[N];
    cin>>n>>q;
    long long a[N];
    for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    s[i]=a[i]-a[i-1];
    while(q--)
    {
        cin>>l>>r>>x;
        s[l]+=x;s[r+1]-=x;
  }
        for(int i=1;i<=n;i++)
    {
        a[i]=s[i]+a[i-1]; 
        if(a[i]<=0)
        cout<<0<<" ";
    else
    cout<<a[i]<<" ";
    }
}
