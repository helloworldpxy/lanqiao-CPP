#include<iostream>
using namespace std;

int main() 
{
  int n;
  cin >> n;
  int count=0;
  bool a[n][n];
//这个地方只有getchar()才行，不知道为什么
  for (int i=0;i<n;i++) 
  {
    for(int j=0;j<n;j++)
    {
      a[i][j]=getchar();
    }
  }

  for(int i=0;i<n-2;i++)
  {
    for(int j=i+1;j<n-1;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        if(a[i][j]&&a[j][k]&&a[j][k])
          count++;
      }
    }
  }
  cout<<count;
}
