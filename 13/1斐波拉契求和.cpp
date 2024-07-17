#include <bits/stdc++.h>
double fib(int n)
{
  if (n==1)
  return 2;
  if (n==2)
  return 3;
  return (fib(n-1)+fib(n-2));
}
int main(int argc, char *argv[])
{
  double sum=0;
  int n;
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
    sum+=(fib(i)/fib(i+1));
  }
  printf("%.5f",sum);
  return 0;
}
