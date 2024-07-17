#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,i,a,b,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",4*a+2*b);
  }
  return 0;
}
