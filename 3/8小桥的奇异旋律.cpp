#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010],n,a1,a2;
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int fla=1;ll all=0;
    for(int i=1;i<=n;i++){
        all+=a[i];
        if(fla>0){
            if(all<=0){
                a1+=1-all;
                all=1;
            }
        }
        else {
            if(all>=0){
                a1+=all+1;
                all=-1;
            }
        }
        fla=-fla;
    }
    
    fla=-1;all=0;
    for(int i=1;i<=n;i++){
        all+=a[i];
        if(fla>0){
            if(all<=0){
                a2+=1-all;
                all=1;
            }
        }
        else {
            if(all>=0){
                a2+=all+1;
                all=-1;
            }
        }
        fla=-fla;
    }
    cout<<min(a1,a2);
    return 0;
}
