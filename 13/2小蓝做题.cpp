#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(int a, int b){
    while(b != 0){
        int t = b;
        b =  a % b;
        a = t;
    }
    return a;
}
ll lcm(int a, int b){
    return a * b/gcd(a,b);

}
ll sum_factor(int n){
    int sum=0;
    while(n%2==0){
        n /= 2;
        sum += 2;
    }
    for(int i=3;i*i<n;i=i+2){
        while(n%i==0){
            n /= i;
            sum += i;
        }
    }
    if(n>2){
        sum += n;
    }
    return sum;
}
int main()
{
  int n;
  cin >> n;
  while(n--){
      int k, num;
      cin >> k >> num;
      ll a = sum_factor(k);
      if(lcm(a,k)==num){
          cout << "YES" <<endl;
      }else{
          cout << "NO" << endl;
      }
  }
  return 0;
}