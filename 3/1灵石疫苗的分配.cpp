#include <iostream>
using namespace std;
int main()
{
  int N, D, cnt1=0, cnt2=0, c1, c2;
  cin >> N >> D;
  int a[N];
  for(int i=0; i<N; i++){
      cin >> a[i];
      if(a[i]<=9 || a[i]>=80)
      {
          cnt1++;
      }
      else{cnt2++;}
  }
  c1 = (cnt1%D==0)? cnt1/D : cnt1/D+1 ;
  c2 = (cnt2%D==0)? cnt2/D : cnt2/D+1 ;
  cout << c1 + c2 << endl;
  
  return 0;
}