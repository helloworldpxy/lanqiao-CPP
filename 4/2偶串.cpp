#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(){
  string s;cin>>s;
  int num=(int)s.size();
  for(int i=0;i<num;++i){
    a[s[i]-'a']++;
  }
  for(int i=0;i<26;++i){
    if(a[i]!=0&&a[i]%2!=0){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}
