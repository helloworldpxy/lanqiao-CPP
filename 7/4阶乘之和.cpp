#include <iostream>
using namespace std;
int main()
{
    //数量级太大就按位计算
    int n, i, j, sum[101], s[101];
    for (i = 1; i <= 100; i++){
        sum[i] = 0; s[i] = 0;
    }
    sum[1] = 1;
    s[1] = 1;
    cin >> n;
    for (j = 2; j <= n; j++) {
        int b = 0;//进位数值
        for (i = 1; i <= 100; i++) {
            int k = sum[i] * j + b;
            sum[i] = k % 10;
            b = k / 10;
        }//sum存放新一级的阶乘结果
        b = 0;//进位数值
        for (i = 1; i <= 100; i++) {
            int k = sum[i] + s[i] + b;
            s[i] = k % 10;
            b = k / 10;
        }//s存放当前阶乘总和
    }
    int k;
    for(i=100;i>=1;i--)
        if (s[i] != 0) {//找到最高位所在位置
            for (k=i;k>=1;k--)
                cout << s[k];//按高位到低位顺序输出
            break;
        }
    return 0;
}
