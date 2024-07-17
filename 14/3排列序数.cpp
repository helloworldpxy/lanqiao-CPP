#include <bits/stdc++.h>
using namespace std;
int main(){
    string str,strx;
    cin>>str;
    strx=str;
    sort(str.begin(),str.end());
    int ans=0;
    do {
        if(strx==str){
            break;
        }
        ans++;
    }while(next_permutation(str.begin(),str.end()));
    cout<<ans<<endl;
    return 0;
}