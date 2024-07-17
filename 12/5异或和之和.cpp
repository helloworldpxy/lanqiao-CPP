#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], cnt[25][5], n; //cnt[i][j]: 第i位j的个数
long long ans;

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    //异或前缀和
    a[i] ^= a[i - 1];
  }

  //[i, j]的异或和 = a[j] ^ a[i - 1]，因为 a ^ b = c，a ^ c = b
  // for(int i = 1; i <= n; i++)
  //   for(int j = i; j <= n; j++)
  //     ans += a[j] ^ a[i - 1];
  //下面就是优化这个步骤

  //遍历二进位每一位
  for(int i = 0; i <= 20; i++)
    //遍历每一个数，j=0就是左右区间相等的情况
    for(int j = 0; j <= n; j++)
      cnt[i][(a[j] >> i) & 1]++;
  //乘法原理，把所有情况乘起来
  for(int i = 0; i <= 20; i++){
    ans += (long long)cnt[i][0] * cnt[i][1] * (1 << i);
  }
  printf("%lld", ans);
}
