#include <iostream>
using namespace std;
int main()
{
  int n,t;
  cin >> n >> t;
  string s;
  cin >> s;
  while(t--){
    int a;
    cin >> a;
    if(a==1){
      cout << s.find('1')+1 << endl;
    }else{
      int b;
      cin >> b;
      if(s[b-1]=='1')
        s[b-1]='0';
      else
        s[b-1]='1';
    }
  }
  return 0;
}
