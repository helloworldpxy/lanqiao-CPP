#include <bits/stdc++.h>
using namespace std;
int main()
{
  int s;cin>>s;
  int num=(pow(10,9)+7);
  vector<int>cnt(s+1);
  cnt[0]=1;
  for(int i=3;i<=s;i++)
  {
    cnt[i]=0;
    for(int j=3;j<=i;j++)
    {
      cnt[i]+=cnt[i-j];
      cnt[i]%=num;
    }
  }
  cout<<cnt[s];
  return 0;
}
