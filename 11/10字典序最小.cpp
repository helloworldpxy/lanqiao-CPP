#include <iostream>
#include <string>
using namespace std;
string str, str_temp, str_min;
int main()
{
  int n;
  cin>>n;

  cin>>str;
  str_min = str;
  str+=str;

  
  for(int i = 0; i < n; i++)
  {
    str_temp = str.substr(i, n);
    if(str_temp < str_min)
    {
      str_min = str_temp;
    }
  }
  cout<<str_min;
  return 0;
}
