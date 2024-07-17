#include<iostream> 
using namespace std;
const int kl=1e5+5;
long long a[kl],b[kl],c[kl];
int main(){
    int n,m,q,p,i,l,f=1e9,t=0;
    cin>>n>>m;
    while(m--){
        cin>>q>>p;
        b[q]++;
        b[p+1]--;
    }
    for(i=1;i<=n;i++){
    a[i]=a[i-1]+b[i];
    if(a[i]>=1e5&&f>a[i]){
        f=a[i];t=1;
    }
}
    for(i=n;i>0;i--){
        if(a[i]<=1e5) c[a[i]]=i;
    }
    if(c[100001]==0&&t) c[100001]=f;
    for(i=1e5;i>0;i--){
        if(c[i]==0) c[i]=c[i+1];
    }
    cin>>m;
    while(m--){
        cin>>q;
        if(c[q]!=0) cout<<c[q]<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
