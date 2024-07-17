//二分+差分 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll a[N],b[N],c[N],d[N],ans[N],sd[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    for(int i = 1; i <= n; i++){
        int l = i;
        int r = n;
    while(l <= r){
        int mid = (l+r)/2;
        if(c[mid] - c[i-1] > a[i]){
            r = mid - 1;
        }else if(c[mid] - c[i-1] < a[i]){
            l = mid + 1;
        }else {
            r = mid - 1;
        }    
    }
    if(l == n + 1) d[i]++;
    else {
        d[i]++;
        d[l]--;
        ans[l] += a[i] - (c[l - 1] - c[i - 1]); 
    }    
    }
    for(int i = 1; i <= n; i++){
        sd[i] = sd[i-1] + d[i];
        ans[i] += sd[i] * b[i];
        cout << ans[i] << ' ';
    }
    return 0;
}
