#include <iostream>
using namespace std;
int a[1010],p[1010];
int o[1010][1010];
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=m;i++)
  {
    cin>>p[i];
    o[p[i]][p[i]+1]=1;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<n;j++)
    {
      if(a[j]>a[j+1])
      {
        if(o[j][j+1]==1)
        {
          swap(a[j],a[j+1]);
        }
        else
        {
          cout<<"NO";
          return 0;
        }
      }
    }
  }
  cout<<"YES";
  return 0;
}
