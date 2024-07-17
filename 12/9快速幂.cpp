//快速幂算法：
//假设要计算base的power次方，base和power均为正整数
//若使用常规的累乘法，时间复杂度将达到O(power)数量级，当power很大时极易运行超时
//使用基于二分指数的快速幂算法可以大大提高计算速度，缩短计算时间
//快速幂的核心算法为：
//若当前指数是偶数，则指数减半(二分指数)，底数取平方，及计算(base*base)的power/2次方
//若当前指数是奇数，则指数减1,变为偶数，外乘base，改为计算base*[(base)的power-1次方]，如此循环
//快速幂算法可以使指数按log2的速度迅速递减，从而提高计算速度
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll quick_power(ll base,ll power,ll k)//快速幂算法，求base的power次方
{
    ll result = 1;//result为最终结果
    while (power > 0)//当指数为正整数时，不断地二分指数
    {
        if (power % 2 == 1)//当前指数为奇数
        {
            power--;//指数power减一
            result = result*base%k;//外乘底数base
        }
        power /= 2;//若不为奇数，则指数减半
        base = base*base%k;//底数取平方
    }
    return result;//返回最终结果
}

//注：快速幂算法实际上是不断地进行判断奇偶和除以2的操作
//而这两种操作都可以化为位运算，位运算的速度更快，可以使性能达到最佳
//判断奇偶：令power与1作与运算，因为奇数的二进制最后一位是1，偶数的二进制最后一位是0
//若与1作与运算后为0，说明二进制最后一位是0，为偶数；反之为奇数
//除以2：用右移1位实现

ll quick_power_bit(ll base, ll power,ll k)
{
    ll result = 1;
    while (power > 0)
    {
        if (power & 1)//与1作与运算，结果不为0，是奇数
        {
            power--;
            result = result*base%k;
        }
        power >>= 1;//右移一位，相当于除以2
        base = base*base%k;
    }
    return result;
}

int main()
{
  ll b,p,k;
  cin>>b>>p>>k;
    //cout << quick_power(3, 16) << endl;
    cout << quick_power_bit(b, p,k) << endl;
    return 0;
}
