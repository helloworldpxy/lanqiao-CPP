#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    do{
        cout<<s<<'\n';
    }while(next_permutation(s.begin(),s.end()));
    return 0;
}