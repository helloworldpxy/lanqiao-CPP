#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;//范围
int n,a[N];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);//排序
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
