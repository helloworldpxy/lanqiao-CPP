#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;cin>>n;
        if(n<=1)cout<<0<<endl;
        else if(n==2)cout<<1<<endl;
        else
        {
            long long a=n/3;
            long long b=n%3;
            if(b==2)cout<<(long long)(a*7+1)<<endl;
            else cout<<(long long)(a*7)<<endl;
        }
    }
}
