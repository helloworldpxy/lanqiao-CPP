#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int p1,p2,p3;
string s,t[100];
bool check(char l,char r) {
    if(l>=97 && l<=122 && r>=97 && r<=122) {
        if(l<r) {
            return true;
        }
    }
    if(l>='0' && l<='9' && r>='0' && r<='9') {
        if(l<r) {
            return true;
        }
    }
    return false;
}
string unfold(char l,char r) {
    string res="";
    if(p1==1) {
        for(char j=l+1; j<r; j++) {
            for(int k=1; k<=p2; k++) {
                res+=j;
            }
        }
        if(p3==2) {
            reverse(res.begin(),res.end());
        }
    } else if(p1==2) {
        for(char j=l+1; j<r; j++) {
            for(int k=1; k<=p2; k++) {
                res+=j-32;
            }
        }
        if(p3==2) {
            reverse(res.begin(),res.end());
        }
    } else if(p1==3) {
        for(char j=l+1; j<r; j++) {
            for(int k=1; k<=p2; k++) {
                res+='*';
            }
        }
    }
    return res;
}
int main() {
    int len=0;
    cin>>p1>>p2>>p3;
    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++) {
        bool flag=false;
        if(s[i]=='-') {
            char l=s[i-1], r=s[i+1];
            if(check(l,r)) {
                cout<<unfold(l,r);
                flag=true;
            }
        }
        if(!flag) {
            cout<<s[i];
        }
    }
    return 0;
}
