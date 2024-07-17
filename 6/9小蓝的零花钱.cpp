#include<bits/stdc++.h>
using namespace std;
const int N=500;
int a[N],suf[N],g[N];
int main(){
  int n,b;
  cin>>n>>b;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    suf[i]=suf[i-1]+(a[i]&1?1:-1);
//    cout<<"i:"<<i<<" suf[i]:"<<suf[i]<<endl;
  }
  //用一个前缀和数组存储是奇数还是偶数，然后通过遍历  利用左右指针遍历
  int ans=0;
  for(int i=1;i<n;i++){
    if(suf[i]==0){
      if(max(a[i],a[i+1])-min(a[i],a[i+1])<=b) g[ans++]=max(a[i],a[i+1])-min(a[i],a[i+1]);
//      cout<<"a[i-1]:"<<a[i-1]<<" a[i+1]:"<<a[i+1]<<endl;
      
    }
  }
  sort(g,g+ans);
  int j=0,sum=0;
  for(int i=0;i<ans;i++){
//      cout<<g[i]<<endl;
    sum+=g[i];
    if(sum<=b) j++;
  }
  cout<<j;
  return 0;
}
