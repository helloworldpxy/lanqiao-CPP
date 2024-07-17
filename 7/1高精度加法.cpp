#include<bits/stdc++.h>
using namespace std;
string add(string a,string b){
    string s;
    int c=0;
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||c>0;i--,j--){
        if(i>=0)  c+=a[i]-'0';
        if(j>=0)  c+=b[j]-'0';
        
        s+=(c%10)+'0';
        c/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<add(a,b);
    return 0;
}
