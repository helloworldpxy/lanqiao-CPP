#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[301][301];
ll pre[301][301];

int main(){
  ll m,n,c,t,k,x1,x2,y1,y2;
  cin>>n>>m>>c;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      cin>>a[i][j];
      pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
    }
  }
  cin>>t;
  while(t--){
    cin>>x1>>y1>>x2>>y2>>k;
    ll sum=0;
    k=k%(c+1);
    sum = pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1]-(x2-x1+1)*(y2-y1+1)*k;
    cout<<sum<<endl;
  }
  
  return 0;
}
