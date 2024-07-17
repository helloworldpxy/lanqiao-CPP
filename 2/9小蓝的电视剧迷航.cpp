#include <iostream>
using namespace std;
int main()
{
  int T,t;
  cin >> T;
  for(int i=0;i<T;i++)
  {
    cin >> t;
    if(t>24)
      cout << "YES" << endl;
    else
      cout << "NO" <<endl;
  }
  return 0;
}
