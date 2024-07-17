#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+9 ;
ll a[ N<<2 ] ;
int n ;
void push_up( int p )
{
    a[ p ] = a[p<<1] + a[p<<1|1] ;
}
void build( int p , int l , int r )
{
    if( l == r )
    {
        cin >> a[ p ] ; return ;
    }
    int mid = (l+r)>>1 ;
    build( p<<1 , l , mid ) ;
    build( p<<1|1 , mid+1 , r ) ;
    push_up( p ) ;
}
void change( int p , int l , int r , int idx , int val )
{
    if( l == r )
    {
        a[ p ] += val ;
        return ;
    }
    int mid = (l+r)>>1 ;
    if( idx <= mid ) change( p<<1 , l , mid , idx , val ) ;
    else change( p<<1|1 , mid+1 , r , idx , val ) ;
    push_up( p ) ;
}
ll query( int p , int l , int r , int L , int R )
{
    if( L <= l && r <= R ) return a[ p ] ;
    ll ans = 0 ;
    int mid = (l+r)>>1 ;
    if( L <= mid ) ans += query( p<<1 , l , mid , L , R ) ;
    if( R > mid ) ans += query( p<<1|1 , mid+1 , r , L , R ) ;
    return ans ;
}
int main()
{
    cin >> n ;
    build( 1 , 1 , n ) ;
    int q ; cin >> q ;
    while( q-- )
    {
        int op , a , b ; cin >> op >> a >> b ;
        if( op == 1 ) change( 1 , 1 , n , a , b ) ;
        else cout << query( 1 , 1 , n , a , b ) << "\n" ;
    }
    return 0 ;
}
