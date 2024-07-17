#include  <bits/stdc++.h>
using namespace std ;
const int N = 1E5+10 ;


int main()  {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0) ;
  int n ; cin >> n ;
  vector<int> vec ;
  for( int i = 1 ; i<=n ; i++ ){

    int data ; cin >> data ;
    vec.push_back(data) ;
  }


  stack<int> sta ;
  for( auto num : vec ){
    if( num )
      sta.push(num ) ;
    else
      if( sta.size() )
        sta.pop() ;
  }


  for( ; sta.size() ; sta.pop() )
    cout << sta.top() << '\n' ;
  return 0 ;
}
