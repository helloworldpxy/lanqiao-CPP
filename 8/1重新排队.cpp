#include <bits/stdc++.h>
using namespace std;
const int N = 1E4+9;
list<int> r;
int main()
{
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    r.push_back(i);
  }
  while(q--){
    int x,y,z;cin>>x>>y>>z;
    r.remove(x);
    list<int>::iterator it2=r.begin();
    if(z==0){
      for(int i=1;;i++){
        if(*it2==y)break;
        else it2++;
      }
      r.insert(++it2,x);
    
  
    }else{
      for(int i=1;;i++){
        if(*it2==y)break;
        else it2++;
      }
      r.insert(it2,x);
    
  
    }
  }
  for(list<int>::iterator it=r.begin();it!=r.end();it++){
    cout<<*it<<" ";
  }
  return 0;
}
