#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,Q;
  int a[100001],b[100001];
  int l,r,h;
  cin>>N>>Q;
  for(int i=0;i<N;i++)
  {
    cin>>a[i];
    if(i==N-1)printf("\n");
  }
  for(int i=1;i<=Q;i++)
  {
    cin>>l>>r>>h;
    int c=0;
    for(int j=l;j<=r;j++)
    {
      if(a[j]>c&&a[j]<=h)c=a[j];
    }
    b[i]=c;
  }
  for(int i=1;i<=Q;i++)
  {
    cout<<b[i]<<endl;
  }
  return 0;
}
