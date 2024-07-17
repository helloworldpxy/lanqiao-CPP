#include<bits/stdc++.h>
using namespace std;
int num[20005];
int main()
{
  int n,a,b;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    scanf("%d:%d",&a,&b);
    num[i]=a*60+b;
  }
  sort(num+1,num+1+n);
  int mintime=1e5;
  for(int i=2;i<=n;i++)
  mintime=min(num[i]-num[i-1],mintime);
  mintime=min(num[1]+24*60-num[n],mintime);
  cout<<mintime<<endl;
  return 0;
}
