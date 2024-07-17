#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+9 ;
int a[ N ] , b[ N ];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n , k ; cin >> n >> k ;
    for( int i = 1 ; i <= n ; i ++ ) cin >> a[ i ] ;
    ll ans = 0 , pos ;
    for( int i = 1 ; i <= n ; i = pos+1 )
    {
        pos = i ;
        for( int j = i ; j <= i+k-1 ; j ++ ) if( a[j] < a[pos] ) pos = j ;
        int val = a[pos] ;
        for( int j = i ; j <= i+k-1 ; j ++ ) a[j] -= val ;
        ans += val ;
        //cout << "pos=" << pos << " ans=" << ans << " i=" << i << "\n" ;
    }
    for( int i = 1 ; i <= n ; i ++ ) ans += a[i] ;
    cout << ans << "\n" ;
    return 0 ;
}
