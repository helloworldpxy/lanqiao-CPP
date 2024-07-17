#include<iostream>
using namespace std;
const int N = 2e6 + 10;

struct Op{
    char dir;
    int x;
}op[N];

int n, m;
bool v[N];
int a[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> op[i].dir >> op[i].x;
    }
    
    int cnt = 0, cnt1 = n - 1;
    for(int i = m - 1; i >= 0; i --){
        if(v[op[i].x]) continue;
        if(op[i].dir == 'R'){
            // cout << op[i].x << endl;
            a[cnt1 --] = op[i].x;
        }
        else a[cnt ++] = op[i].x;
        v[op[i].x] = true;
    }
    for(int i = 1; i <= n; i ++){
        if(!v[i]) a[cnt ++] = i;
    }
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
        cout << endl;
    return 0;
}
