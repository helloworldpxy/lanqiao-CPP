#include<iostream>
using namespace std ;
int main()
{
    int ans = 0 ;
    for( int a = -3 ; a <= 3 ; a ++ )
    {
        for( int b = -3 ; b <= 3 ; b ++ )
        {
            for( int c = -3 ; c <= 3 ; c ++ )
            {
                if( a*a*a + b*b*b + c*c*c == 3*a*b*c )
                    ans ++ ;
            }
        }
    }

    cout << ans ;

    return 0;
}
