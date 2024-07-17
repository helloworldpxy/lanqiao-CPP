#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> my_list;
  for(int i=1;i<=10;i++)my_list.push_back(i);
  int n;cin>>n;
  while(n--){
    int x;cin>>x;
    for(int i=0;i<10;i++){
      if(my_list[i]==x){
        my_list.erase(my_list.begin()+i);
        my_list.insert(my_list.begin(), x);
        break;
      }
    }
  
    for(int i=0;i<10;i++){
      cout<<my_list[i]<<' ';
    }
    cout<<endl;
  }
  return 0;
}
