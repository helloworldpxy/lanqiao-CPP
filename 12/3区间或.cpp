#include<bits/stdc++.h>
using namespace std;
const int N=1E5+9;
int a[N],prefix[35][N];
int main()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int w=0;w<=30;w++)//第0位到第30位 
    {
        for(int i=1;i<=n;i++)
        {
           prefix[w][i]=prefix[w][i-1]+(a[i]>>w&1);//取出第w位的数字    
        } 
    } 
    while(q--)
    {
        int l,r;cin>>l>>r;
        int ans=0;
        for(int w=0;w<=30;w++)
        {
            ans+=(1<<w)*(prefix[w][r]-prefix[w][l-1] ? 1 : 0);
        }
        cout<<ans<<endl;
    } 
    return 0;
}
