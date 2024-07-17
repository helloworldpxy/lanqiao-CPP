#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+5;
int a[N];
int main(){
    int n;
    cin>>n;  
    for(int i = 1;i <=n ;++i)
    {
        cin>>a[i];
    }
    stack<int> st;
    int k = INT_MIN,INF = INT_MAX;
    //min_r[i]表示i右边最小的数
    vector<int> min_r(n+1,INF);
    for(int i = n - 1;i >= 1;--i){
        min_r[i] = min(min_r[i+1],a[i+1]);
    }
    //d<c<a<b...k对应a,a[i]为b,min_r[i]为d
    for(int i = 1;i <= n;++i){
        
        if(a[i] < k){
            if(a[i] > min_r[i]) 
            {
                cout << "YES";
                return 0;
            }
        }

        while(!st.empty()&&st.top() < a[i]){
            k = max(k,st.top());
            st.pop();
        }
        st.push(a[i]);
    }
    cout<< "NO";

    return 0; 
    
}
