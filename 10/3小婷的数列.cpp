#include<bits/stdc++.h>
using namespace std;
vector<long>a;
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  long q,ans;
  cin>>q;
  while(q--)
  {
    int op;
    long x;
    cin>>op;
    if(op==1)
    {
      cin>>x;
      a.push_back(x);
      ans=-1;
      for(auto &y:a)if(ans<y)ans=y;
      cout<<ans<<'\n';
    }
    else
    {
      if(a.empty()){cout<<"-1"<<'\n';continue;}
      a.erase(a.begin());
      if(!a.empty())
      {
        ans=-1;
        for(auto &y:a)if(ans<y)ans=y;
        cout<<ans<<'\n';
      }
      else cout<<"-1"<<'\n';
    }
  }
  return 0;
}
