#include <iostream>
#include<algorithm>
using namespace std;
const int N=5e5+7;
int a[N];
int bucket[N];
//#define all(s) s.begin(),s.end()
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    int x;
    cin>>x;
    bucket[x]++;//桶中同一元素的值加一
  }
  for(int i=0;i<=n;++i)
  {
    for(int j=1;j<=bucket[i];++j)
      cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
