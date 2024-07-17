#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
signed main()
{
  int min_=0x3f3f3f3f,max_=0;
  do{
    int sum=0;
    if(a[0]==0) continue;
    for(int i=0;i<10;i++)
    {
      sum=sum*10+a[i];
    }
    if(sum%11) continue;
    if(sum>max_) max_=sum;
    if(sum<min_) min_=sum;
  }while(next_permutation(a,a+10));
  cout<<max_-min_;
  return 0;
}
