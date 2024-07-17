#include <bits/stdc++.h>
using namespace std;
int num[10]={1,2,3,4,5,6,7,8,9};
int cnt;
int func(int a,int b)
{
  int sum=0;
  for(int i=a;i<=b;i++)
  {
    sum=sum*10+num[i];
  }
  return sum;
}
int main()
{
  int n;
  cin>>n;
  while(next_permutation(num,num+9))
  {
    for(int i=0;i<9;i++)
    {
      int a=func(0,i);
      for(int j=i+1;j<9;j++)
      {
        int b=func(i+1,j);
        int c=func(j+1,8);
        if(n*c==a*c+b)
        {
          cnt++;
        }
      }
    }
  }
  cout<<cnt;
  return 0;
}
