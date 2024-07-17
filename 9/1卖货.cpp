#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll dp[N]; // 表示以位置 i 为结尾的合法数列个数
int stk[N];// 堆栈，存放 1 的最右边的位置 
int top = 0; 
int main()  
{
    int n; cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        int x; cin >> x;
        if(x == 1){
            stk[++top] = i;
        }
        else if(top)
        {
            dp[i] = dp[stk[top --] - 1] + 1;
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i ++)    ans += dp[i];
    cout << ans << endl;
    return 0;
}
