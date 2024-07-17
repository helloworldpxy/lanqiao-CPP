#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],col[N],ans;
vector<int>pla[N];

void merge(int x,int y)
{
  if(!pla[x].size()) return ;
  for(int i=0;i<pla[x].size();i++)
  ans-=((a[pla[x][i]-1]==y)+(a[pla[x][i]+1]==y));
  for(int i=0;i<pla[x].size();i++)
  {
    a[pla[x][i]]=y;pla[y].push_back(pla[x][i]);
  }
  pla[x].clear();
}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    col[a[i]]=a[i];
    if(a[i]!=a[i-1])
    ans++;
    pla[a[i]].push_back(i);
  }

  while(m--)
  {
    int opt;
    cin>>opt;
    if(opt==2)
    cout<<ans<<endl;
    else
    {
      int x,y;
      cin>>x>>y;
      if(x==y) continue;
      if(pla[col[x]].size()>pla[col[y]].size())
      swap(col[x],col[y]);
      merge(col[x],col[y]);
    }
  }
  return 0;
}
