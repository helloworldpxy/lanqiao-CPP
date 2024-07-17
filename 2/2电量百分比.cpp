#include<iostream>
using namespace std ;
int main()
{

    for( int x = 14 , y = 68 ; ; x+=4 , y += 1 )
    {
        if( x == y )
        {
            cout << x << "\n" ;
            break ;
        }
    }
    return 0;
}
