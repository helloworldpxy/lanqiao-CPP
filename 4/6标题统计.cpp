//标题统计
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int ans=0;
    while(cin>>c)
    {
        if(c!=' '&& c!='\n')
        ans++;
    }
    cout<<ans;
    return 0;
 }
