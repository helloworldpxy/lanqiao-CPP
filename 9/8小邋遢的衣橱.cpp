#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<string> z;
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string a,b;
    cin>>a>>b;
    if(a=="in") z.push(b);
    else
    {
      A : if(z.top()==b) z.pop();
      else
      {
      while(1)
      {
        z.pop();
        if(z.top()==b) goto A;
      }
      }
    }
  }
  if(z.size()==0) cout<<"Empty";
  else cout<<z.top();
  return 0;
}
