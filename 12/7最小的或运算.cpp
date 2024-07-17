#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dec(int n);
int binary(unsigned long long num,unsigned long long arr[]);
unsigned long long a,b,a1[100] = {0},b1[100] = {0},c1[100] = {0},sum = 0;
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  scanf("%llu %llu",&a,&b);
  int count1 = binary(a,a1);
  int count2 = binary(b,b1);
  int n;
  if(a == b)
  {
    printf("0");
    return 0;
  }
  if(count1 > count2)
  {
    n = count1;
  }else n = count2;
  for(int i = 0;i < n;i++)
  {
    if(a1[i] == b1[i])
    {
      c1[i] = 0;
    }else c1[i] = 1;
  }
  dec(n);
  printf("%llu",sum);
  return 0;
}
int dec(int n)//十进制
{
  int i = 0;
  while(i < n)
  {
      sum += (c1[i] * pow(2,i));
      i++;
  }
  
  return 0;
}
int binary(unsigned long long num,unsigned long long arr[])//二进制
{
  int i = 0;
  while(num > 0)
  {
    arr[i] = num % 2;
    num /= 2;
    i++;
  }
  return i;
}
