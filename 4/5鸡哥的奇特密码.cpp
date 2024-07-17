#include<bits/stdc++.h>
using namespace std;
char a[100005];
int flag=0;
int main(){
  cin>>a;
  int i=0;
  while(a[i]!='\0'){
    if (flag==0){
      if (a[i]=='L') flag=1;
      cout<<a[i];
    }
    else{
      if (a[i]=='Q') {
        flag=0;
        cout<<a[i];
      }
    }
    i++;
  }
  return 0;
}
