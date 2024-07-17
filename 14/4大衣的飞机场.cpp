#include <bits/stdc++.h>
using namespace std;
const long long N=1e3+9;
long long n;
map<long long,long long> a;
int main(){
    cin>>n;
    for(int i=1;i<=2*n;++i){
        long long x;
            cin>>x;
        a[x]++;
    }
    long long mx=0;
    map<long long, long long >::iterator it1;
    for(it1 = a.begin(); it1!= a.end(); it1++){
        if(mx < it1->second) mx = it1->second;
    }
    cout<<mx;
    return 0;
}