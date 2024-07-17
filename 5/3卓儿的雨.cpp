#include <iostream>
using namespace std;
int n,m,w;
int g[1000005];
int d[1000005];
int main()
{
  cin>>n>>m>>w;
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    r++;l++;
    d[l]++;
    d[r+1]--;
  }
  for(int i=1;i<=w;i++){
   // if(i!=0)
    g[i]=d[i]+g[i-1];
  }
  for(int i=0;i<m;i++){
    int x;
    cin>>x;
    cout<<g[x+1]<<endl;
  }
  return 0;
}
