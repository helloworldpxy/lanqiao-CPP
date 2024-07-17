#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
int arr[100005];
int c[100005];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        int t =arr[i];
        if(m.count(t)==0){
            arr[i]=-1*t;
            c[i]=1;
            m[t]=i;
        }else{
            int sum=0;
            for (int j = m[t]; j < i-1; ++j) {
                sum+=c[j];
            }
            arr[i]=sum;
            --c[m[t]];
            ++c[i];
            m[t]=i;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
