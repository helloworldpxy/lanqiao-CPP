#include <iostream>
using namespace std;
int main()
{
  int N,a[1000],sum1=0,sum2=0,sum3=0,min;
  cin >> N;
  for(int i=0;i<N;i++)
  {
    cin >> a[i];
  }
  for(int i=0;i<N;i++)
  {
    if(a[i]==0)
      sum1++;
    else if(a[i]==1)
      sum2++;
    else
      sum3++;
  }
  min=2*sum2+sum3;
  if(min>2*sum3+sum1)
    min=2*sum3+sum1;
  if(min>2*sum1+sum2)
    min=2*sum1+sum2;
  cout << min <<endl;
  return 0;
}
