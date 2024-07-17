#include <iostream>
using namespace std;
int main()
{
  int T;
  long X, Y;
  cin >> T;
  while(T--){
      cin >> X >> Y;
      if( X > Y){
          cout << "BRIDGE" << endl;
      }
      else if( X < Y){
          cout << "YI" << endl;
      }
      else{
          cout << "ANY" << endl;
      }
  }
  return 0;
}