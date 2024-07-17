#include <iostream>
#include  <queue>
using namespace std;
queue<int>q;
int main()
{
  int n,m,add;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>m;
    switch(m)
    {
      case 1:{cin>>add;q.push(add);break;}
      case 2:q.pop();break;
      case 3:cout<<q.front()<<" "<<q.back()<<endl;break;
    }
  }
  return 0;
}
