#include <bits/stdc++.h>
using namespace std;
int a;
void micifang(int x){
  for(int i=14;i>=0;i--){
    if(pow(2,i)<=x){
      if(i==1) cout<<"2";
      else if(i==0) cout<<"2(0)";
      else{
        cout<<"2(";
        micifang(i);
        cout<<")";
      }
      x-=pow(2,i);
      if(x!=0) cout<<"+";
    }
  }
}
int main()
{
    cin>>a;
    micifang(a);
    return 0;
}
