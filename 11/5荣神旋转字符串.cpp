#include <iostream>
#include<cstring>
using namespace std;
int main()
{
  string ans;cin>>ans;
  string s=ans;
  for(int i=0;i<s.size();i++)
  {
    s=s.substr(1)+s[0];
    if(ans>s) ans=s; 
  }
  cout<<ans;
  return 0;
}
