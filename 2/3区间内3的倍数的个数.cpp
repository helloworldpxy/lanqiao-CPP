#include <iostream>
using namespace std;
int main()
{
  int a,b,n=0;
  cin >> a >> b;
  for(int i=a;i<=b;i++)
  {
    if(i%3==0)
      n++;
  }
  cout << n << endl;
  return 0;
}
