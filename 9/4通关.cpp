#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll>pa;
pa t1;
priority_queue<pa,vector<pa>,greater<pa>>qu;
struct node{
    ll si,ki;
    vector<ll>ve;
}a[100020];
int main(){
    ll n,p,t,ans=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>t>>a[i].si>>a[i].ki;
        a[t].ve.push_back(i);//进入父节点，然后在父节点里面存入这个父节点的子节点，方便后面调用 
    }
    qu.push({a[1].ki,1});//堆是pair类型， 这里1的意思是它在a里面的位置 
    while(qu.empty()==0){
        t1=qu.top();
        qu.pop();
        if(t1.first>p)break;//p是他现有的分数，小于推顶分数的话，直接结束 
        p+=a[t1.second].si;
        ans++;
        for(int i=0;i<a[t1.second].ve.size();i++)//因为这个节点通过了，把这个节点的所有子节点放入推 
                      qu.push({a[a[t1.second].ve[i]].ki,a[t1.second].ve[i]});
    }
    printf("%lld",ans);
    return 0;
}
