#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 123123 偶 n%10^(a/2) n/10^(a/2)  123==123
  long long n,a=0,t=1,b,k;
  cin>>n;
  k=n;//k用来保存n的值
  while(n){n/=10;a++;}//a用来统计位数
  if(a%2)cout<<"no";
  else {
    a/=2;
    while(a-->0)t*=10;
        b=k%t;//b为右边一半
        k/=t;
        if(k==b)cout<<"yes";
        else cout<<"no";
  }
  return 0;
}
