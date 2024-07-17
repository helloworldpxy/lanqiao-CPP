#include <iostream>
using namespace std;
int T;
int main()
{
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    int x=0,y=0;
    scanf("%d %d",&x,&y);
    if(5*x>=y)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
