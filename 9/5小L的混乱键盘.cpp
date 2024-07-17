#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    queue<char> q;
    stack<char> s;
    string a,b;
    cin>>a>>b;
    int n=a.length(),i;
    for(i=0;i<n;++i)
    {
        if(b[i]=='L')
            s.emplace(a[i]);
        else
            q.emplace(a[i]);
    }
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
