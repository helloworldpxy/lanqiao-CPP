#include <bits/stdc++.h>
using namespace std;
int main() {
    long long i, j, t = 1, B[10005] = {0}, n;//t表示位数
    cin >> n;
    B[1] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= t; j++)B[j] *= i;//求i的阶乘
        for (j = 1; j <= t; j++)        //对i的阶乘进位
            if (B[j] > 9) {
                B[j + 1] += B[j] / 10;
                B[j] %= 10;
                if (B[t+1] > 0)t++;
            }
    }
    for (j = t; j >= 1; j--) cout << B[j];
    return 0;
}
