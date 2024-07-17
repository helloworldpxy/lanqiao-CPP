#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e5 + 5;
long long a[N], diff[N];//极限计算1e5 * 1e9 > INT_MAX，所以使用long long 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    cin >> n >> k;
    long long ans = 0;
  //对正面数字进行累加
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i];
    }
  //计算差值数组
    for(int i = 1; i <= n; i++){
        cin >> diff[i];
        diff[i] -= a[i];
    }
  //对差值数组进行降序排序
    sort(diff + 1, diff + n + 1, greater<long long>());

    k = min(k, n);//操作次数不能超过n次，k < 1e9，会超出数组范围导致运行错误
    for(int i = 1; i <= k; i++){
        if(diff[i] > 0)ans += diff[i];//差值大于0使得翻转后总值增加
        else break;//降序排列，后续值无作用
    }
    cout << ans;
    
    return 0;
}
