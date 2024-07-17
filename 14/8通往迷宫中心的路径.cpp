#include <bits/stdc++.h>
using namespace std;
int a[12]={0,1,2,3,4,5,6,7,8,9,10,11};
int main()
{
 int max_=0,ans=0;
 do{
   int sum=0;
   for(int i=1;i<=11;i++)
   {
     sum+=abs(a[i]-i-3);
   }
   if(sum>max_) 
   {
     max_=sum;
     ans=0;
   }
   if(sum==max_) ans++;
 }while(next_permutation(a+1,a+12));
 cout<<ans;
  return 0;
}