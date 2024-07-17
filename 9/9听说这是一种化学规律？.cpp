#include  <bits/stdc++.h>
using namespace std ;


int main()  {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0) ;
  string sdata ; cin >> sdata ;  



  for( int i = 0 ; i<sdata.size() ; i++ ) {
    auto &ch = sdata[ i ] ;

    if( ch=='5' || ch=='7' ) {
      sdata.erase( sdata.begin()+i , sdata.begin()+i+1 ) ;
      i-- ; 
    }
    if( ch=='6' )
      ch = '9' ;
  }



  stack<int> sta ;
  for( int i = 0 ; i<sdata.size() ; i++ ){
    if( sdata[i] == '3' ) 
      sta.push( i ) ;

    if( sdata[i] == '4' )
      if( sta.size() ){

        swap( sdata[i],sdata[sta.top()] ) ;
        sta.pop() ;
      }
  }



  cout << sdata << '\n' ; 
  return 0 ; 
}
