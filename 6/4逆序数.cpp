#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int q[N],tmp[N];
long long cnt=0;

void merge_sort(int q[],int l,int r){
  if(l>=r) return;

  int mid=l+r>>1;
  merge_sort(q,l,mid);
  merge_sort(q,mid+1,r);

  int k=0,i=l,j=mid+1;
  while(i<=mid&&j<=r){
    if(q[i]<=q[j]) tmp[k++]=q[i++];
    else{
      tmp[k++]=q[j++];
      cnt+=mid-i+1;
    }
  }
  while(i<=mid) tmp[k++]=q[i++];
  while(j<=r) tmp[k++]=q[j++];

  for(int i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) scanf("%d",&q[i]);
  merge_sort(q,0,n-1);
  cout<<cnt<<endl;
  return 0;
}
